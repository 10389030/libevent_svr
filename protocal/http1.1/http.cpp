
#include "http.h"
#include <iostream>

namespace protocal {
    namespace http {

        using namespace std;
            
        std::regex URI::pattern("\\s*([^:]+):(//((([^:\\s]+)(:(\\w+))?)@)?(([^:\\s]+)(:(\\d+))?))?(#(\\w+))?");
        
        URI::URI(const string& param)
            : src(param) {

            std::smatch sm;
            bool isMatch = std::regex_match(param, sm, URI::pattern);
            if (!isMatch) {
                throw __func__;
            }

            for (auto& grp: sm) {
                cout << grp << endl; 
            }
        }





        int http_listen(const string& param) {
            return 0;
        }

        int http_accept(int listen_fd) {
            return 0;
        }

        int http_check(evbuffer* ev) {
            return 0;
        }

        int http_process(evbuffer* in, evbuffer* out) {
            return 0;
        }

        int http_error(int client_fd) {
            return 0;
        }
    }
}
