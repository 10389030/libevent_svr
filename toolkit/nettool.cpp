#include "nettool.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <stdio.h>

#include <glog/logging.h>


namespace toolkit {
    namespace network {

        SocketFDInfo::SocketFDInfo(int fd): fd(fd) {
            sockaddr_in addr;
            socklen_t sock_len = sizeof(sockaddr_in);

            int ret = 0;
            // get host info
            ret = getsockname(fd, (sockaddr*)&addr, &sock_len);
            LOG_IF(WARNING, ret != 0) << "getpeername for " << fd 
                << ", errno: " << errno << ": " << strerror(errno) << endl;
            hostIP = inet_ntoa(addr.sin_addr);
            hostPort = ntohs(addr.sin_port);


            ret = getpeername(fd, (sockaddr*)&addr, &sock_len);
            LOG_IF(WARNING, ret != 0) << "gethostname for " << fd 
                << ", errno: " << errno << ": " << strerror(errno) << endl;
            peerIP = inet_ntoa(addr.sin_addr);
            peerPort = ntohs(addr.sin_port);
        }

        string SocketFDInfo::Host() const {
            char buff[] = "255.255.255.255:65536";
            snprintf(buff, sizeof(buff), "%s:%d", hostIP.c_str(), hostPort);
            return buff;
        }


        string SocketFDInfo::Peer() const {
            char buff[] = "255.255.255.255:65536";
            snprintf(buff, sizeof(buff), "%s:%d", peerIP.c_str(), peerPort);
            return buff;
        }


        string SocketFDInfo::ToString() const {
            char buf[] = "{fd:65536, hostIP:255.255.255.255, hostPort:65536, peerIP:255.255.255.255, peerPort: 65536}";
            snprintf(buf, sizeof(buf), "{fd:%d, hostIP:%s, hostPort:%u, peerIP:%s, peerPort:%u}", fd, hostIP.c_str(), hostPort, peerIP.c_str(), peerPort);
            return buf;
        }

        ostream& operator << (ostream& os, const SocketFDInfo& inst) {
            os << inst.ToString();
            return os;
        }
    }
}
