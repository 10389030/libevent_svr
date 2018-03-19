#ifndef __PROTOCAL_HTTP_H_
#define __PROTOCAL_HTTP_H_

#include <regex>
#include <event.h>

namespace protocal {
    namespace http {
        
        using namespace std;

        int http_listen(const string& param);
        int http_accept(int listen_fd);
        int http_check(evbuffer* evbuf);
        int http_process(evbuffer* in, evbuffer* out);
        int http_error(int client_fd);


        // scheme:[//[user[:password]@]host[:port]][/path][?query][#fragment]
        class URI {
            public:
                const string src;

            private:
                static std::regex pattern;

            public:
                string scheme;
                string user;
                string passwd;
                string host;
                unsigned short port;
                string path;
                string fragment;
                
                URI(const string& param);
        };
    }
}

#endif
