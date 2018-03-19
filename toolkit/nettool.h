#ifndef __TOOLKIT_NETWORK_NETTOOL_H_
#define __TOOLKIT_NETWORK_NETTOOL_H_

#include <string>
#include <iostream>

namespace toolkit {
    namespace network {
        
        using namespace std;

        class SocketFDInfo {
            public:
                SocketFDInfo(int fd);    

                string Host() const;         
                string Peer() const;

                string ToString() const;
                friend ostream& operator << (ostream&, const SocketFDInfo&);

            public:
                string hostIP;
                string peerIP;
                unsigned short hostPort;
                unsigned short peerPort;

            private:
                const int fd;
        };
    }
}

#endif
