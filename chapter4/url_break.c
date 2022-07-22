//
// Created by weipeng2k on 2022/7/22.
//

#include <stdlib.h>
#include <string.h>
#include "url_break.h"

/**
 * 根据字符串创建一个protocal
 * @param link
 * @return
 */
static char *create_protocol(char *link) {
    int index = 0;
    char *p = link;
    while (*p) {
        if (*p == ':') {
            break;
        }
        index++;
        p++;
    }

    char *protocol = malloc(sizeof(char) * (index + 1));

    char *pp = protocol;
    p = link;

    for (int i = 0; i < index; i++) {
        *pp = *p;
        pp++;
        p++;
    }
    *pp = '\0';
    return protocol;
}

/**
 * 根据字符串创建一个host
 * @param link
 * @return
 */
static char *create_host(char *link) {
    int startIncludeIndex = 0;
    int endExcludeIndex = 0;

    char *p = link;
    while (*p) {
        // 找到//中最后一个/
        if (*p == '/' && *(p + 1) != '/') {
            startIncludeIndex++;
            break;
        }
        p++;
        startIncludeIndex++;
    }

    p = link + startIncludeIndex;
    endExcludeIndex = startIncludeIndex;
    while (*p) {
        if (*p != '/' && (*(p + 1) == '/' || (*(p + 1)) == ':')) {
            break;
        }
        p++;
        endExcludeIndex++;
    }

    char *host = malloc(sizeof(char) * (endExcludeIndex - startIncludeIndex + 1));
    char *hp = host;

    p = link + startIncludeIndex;
    int length = endExcludeIndex - startIncludeIndex;
    for (int i = 0; i <= length; i++) {
        *hp = *p;
        hp++;
        p++;
    }
    *hp = '\0';

    return host;
}

/**
 * 根据字符串找到端口
 * @param link 链接
 * @return 端口
 */
static int create_port(char *link) {
    int port = 80;
    char *p = link;
    int flag = 0;

    while (*p) {
        if (*p == ':') {
            flag++;
        }
        if (*p == ':' && flag == 2) {
            p++;
            break;
        }
        p++;
    }

    if (flag == 2) {
        char *start = p;
        int length = 0;

        while (*p) {
            if (*p == '/') {
                break;
            }
            p++;
            length++;
        }

        char *port_str = malloc(sizeof(char) * (length + 1));
        char *psp = port_str;

        for (int i = 0; i < length; i++) {
            *psp = *start;
            start++;
            psp++;
        }
        *psp = '\0';

        port = atoi(port_str);

        free(port_str);
    }

    return port;
}

/**
 * 根据字符串找到资源，资源是由/开始的，也就是找到单独的/
 * @param link 链接
 * @return 资源
 */
char *create_resource(char *link) {
    char *p = link;
    int startIndex = 0;

    while (*p) {
        // 单独的/
        if (*p == '/' && *(p + 1) != '/') {
            break;
        }
        startIndex++;
        p++;
    }

    int length = (int)strlen(link) - startIndex;
    char *resource = malloc(sizeof(char) * length);
    char *rp = resource;

    for (int i = 0; i < length; i++) {
        *rp = *p;
        rp++;
        p++;
    }

    return resource;
}

/**
 * 根据字符串创建一个URL
 * @param link 字符串
 * @return url
 */
url *create_url(char *link) {
    url *u = malloc(sizeof(url));
    u->protocol = create_protocol(link);
    u->host = create_host(link);
    u->port = create_port(link);
    u->resource = create_resource(link);
    return u;
}

/**
 * TEST
 * @return
 */
//int main(void) {
//    char *link = "https://www.baidu.com";
//    char *protocol = create_protocol(link);
//    puts(protocol);
//
//    link = "tcp://www.baidu.com:999/ccav/index.html";
//    protocol = create_protocol(link);
//    puts(protocol);
//
//
//    char *host = create_host(link);
//    puts(host);
//
//    int port = create_port(link);
//    printf("%i\n", port);
//
//    url *u = create_url(link);
//    printf("PROTOCOL:%s\n", u->protocol);
//    printf("HOST:%s\n", u->host);
//    printf("PORT:%i\n", u->port);
//    printf("RESOURCE:%s\n", u->resource);
//
//    return 0;
//}