#include <iostream>
#include <stdio.h>
#include <memory>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <event.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <glog/logging.h>
#include "toolkit/network/nettool.h"

using namespace std;

void client_read_callback(struct bufferevent* bev, void* arg) {
    int client_fd = bufferevent_getfd(bev);
    LOG(ERROR) << __func__ << ": " << toolkit::network::SocketFDInfo(client_fd);

    evbuffer* evb = bufferevent_get_input(bev);
    int buffer_len = evbuffer_get_length(evb);

    char *buf = (char*)malloc(buffer_len+1);
    shared_ptr<char> auto_buf(buf, free);

    bufferevent_read(bev, buf, buffer_len);
    buf[buffer_len] = '\0';
    LOG(ERROR) << "recv msg: " << buf;

    evbuffer* rsp_buf = evbuffer_new();
    shared_ptr<evbuffer> auto_rsp_buf(rsp_buf, evbuffer_free);

    evbuffer_add_printf(rsp_buf, "HTTP/1.1 200 OK\r\n");
    evbuffer_add_printf(rsp_buf, "Content-Type: text/plain\r\n");
    evbuffer_add_printf(rsp_buf, "Content-Length: %d\r\n", strlen(buf));
    evbuffer_add_printf(rsp_buf, "\r\n");
    evbuffer_add_printf(rsp_buf, "%s", buf);


    bufferevent_write_buffer(bev, rsp_buf);
}



void client_error_callback(struct bufferevent* bev, short what, void* arg) {
    LOG(ERROR) << __func__;

    int client_fd = bufferevent_getfd(bev);
    bufferevent_free(bev);
    LOG(ERROR) << "client close:" << what << " " << toolkit::network::SocketFDInfo(client_fd);
    close(client_fd);
}



void accept_callback(int fd, short ev, void* arg) {
    struct sockaddr_in host_addr;
    socklen_t sock_len = sizeof(struct sockaddr_in);
    getsockname(fd, (struct sockaddr*)&host_addr, &sock_len);
    LOG(ERROR) << __func__ << ": " << toolkit::network::SocketFDInfo(fd);

    int client_fd = accept(fd, NULL, NULL);
    if (client_fd < 0) {
        LOG(ERROR) << strerror(errno);
        return;
    }

    evutil_make_socket_nonblocking(client_fd);
    struct bufferevent* bev = bufferevent_new(client_fd, client_read_callback, NULL, client_error_callback, NULL);

    bufferevent_enable(bev, EV_READ);
};


int main(int argc, const char* argv[]) {
    google::InitGoogleLogging(argv[0]);

	int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_fd < 0) {
		LOG(ERROR) << strerror(errno);	
	}
	
	struct sockaddr_in listen_addr;
	bzero(&listen_addr, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(80);
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    int bind_ret = bind(listen_fd, (struct sockaddr*)&listen_addr, sizeof(listen_addr));
    if (bind_ret < 0) {
        LOG(ERROR) << strerror(errno);
    }

    int listen_ret = listen(listen_fd, 16);
    if (listen_ret < 0) {
        LOG(ERROR) << strerror(errno);
    }

    int reuse = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    evutil_make_socket_nonblocking(listen_fd);
	
	event_init();
    struct event accept_event;
    event_set(&accept_event, listen_fd, EV_READ|EV_PERSIST, accept_callback, NULL);
    event_add(&accept_event, NULL);

    sockaddr_in sock_addr;
    socklen_t sock_len = sizeof(sockaddr_in); 
    getsockname(listen_fd, (sockaddr*)&sock_addr, &sock_len);

    toolkit::network::SocketFDInfo listen_info(listen_fd);
    LOG(ERROR) << "server listen on: " << listen_info << endl;

    event_dispatch();

    close(listen_fd);

	return 0;
}
