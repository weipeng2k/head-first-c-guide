// 根据URL访问对应的网页
// Created by weipeng2k on 2022/7/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include "include/url_break.h"

/**
 * 输出错误
 * @param msg
 */
void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

int open_socket(char *host, char *port) {
    struct addrinfo *res;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port, &hints, &res) == -1) {
        error("can not resolve the address");
    }

    int d_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (d_sock == -1) {
        error("can not open socket");
    }

    int c = connect(d_sock, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);

    if (c == -1) {
        error("can not connect socket");
    }

    return d_sock;
}

int say(int socket, char *s) {
    int result = send(socket, s, strlen(s), 0);
    if (result == -1) {
        fprintf(stderr, "%s, %s\n", "error send msg to server", strerror(errno));
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error("arg need 2");
    }

    char *link = argv[1];
    char port[20] = {0};
    url *u = create_url(link);
    sprintf(port, "%d", u->port);

    int d_sock = open_socket(u->host, port);

    char buf[255];
    sprintf(buf, "GET %s http/1.1\r\n", link);
    say(d_sock, buf);
    say(d_sock, "Accept: */*\r\n");
    sprintf(buf, "Host: %s\r\n\r\n", u->host);
    say(d_sock, buf);

    free(u->host);
    free(u->resource);
    free(u->protocol);
    free(u);

    char rec[256];
    int bytesRcvd = recv(d_sock, rec, 255, 0);

    while (bytesRcvd) {
        if (bytesRcvd == -1) {
            error("can not read form server");
        }

        rec[bytesRcvd] = '\0';
        printf("%s", rec);
        bytesRcvd = recv(d_sock, rec, 255, 0);
    }

    close(d_sock);

    return 0;
}
