#ifndef __PROTOCAL_INTERFACE_H_
#define __PROTOCAL_INTERFACE_H_

#include <string>
#include "http1.1/http.h"

namespace protocal {
    
    using namespace std;

    typedef int (*ListenHander)(const string& param);
    typedef int (*AcceptHander)(int listen_fd);
    typedef int (*CheckMsgHander)(evbuffer* evbuf);
    typedef int (*ProcessHandler)(evbuffer* in, evbuffer* out);
    typedef int (*ErrorHandler)(int client_fd);


    struct ServeHandler {
        ListenHander listenHandler;
        AcceptHander acceptHandler;
        CheckMsgHander checkMsgHandler;
        ProcessHandler processHandler;
        ErrorHandler errorHandler;
    };


    const http_serveHandler = ServeHandler {
        protocal::http::http_listen,
        protocal::http::http_accept,
        protocal::http::http_check,
        NULL, // should implement
        protocal::http::http_error
    };
}

#endif
