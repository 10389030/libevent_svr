
#include "http.h"
#include <iostream>
#include <vector>

namespace protocal {
    namespace http {

        using namespace std; 
        
        // scheme:[//[user[:password]@]host[:port]][/path][?query][#fragment]
        string str_regex = ("(?:\\s*" // prefix
            "([^:]+):"  // scheme
            "(?://"
                "(?:"
                    "([^:\\s]+)" // user
                    "(?:"
                        ":(\\w+)" // password
                    ")?"
                "@)?"
                "([^:/?#\\s]+)" // host
                "(?:"
                    ":(\\d+)"  // port
                ")?"
            ")?"
            "(/[^?#\\s]*)?" // path
            "(?:[?]([^#\\s]*))?" // query
            "(?:#(\\w*))?" // fragment
            ".*)" // suffix
        );
        // string str_regex = ("\\s*([^:]+):(?://(?:([^:\\s]+)(?::(\\w+))?@)?([^:/\?#\\s]+)(?::(\\d+))?)(/[^\?#\\s]+)?(?:\?([^#\\s]+))\?(?:#(\\w+))?.*");
        std::regex URI::pattern(str_regex);
        vector<string> fields = {
            "all",
            "scheme",
            "user",
            "password",
            "host",
            "port",
            "path",
            "query",
            "fragment"
        };

        URI::URI(const string& param)
            : src(param) {

                std::smatch sm;
                bool isMatch = std::regex_match(param, sm, URI::pattern);
                if (!isMatch) {
                    throw __func__;
                }

                for (size_t i = 0; i < sm.size(); ++i) {
                    cout << fields[i] << ": " << sm[i] << endl; 
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
