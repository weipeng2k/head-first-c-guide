//
// Created by weipeng2k on 2022/7/22.
//

#ifndef HEAD_FIRST_C_URL_BREAK_H
#define HEAD_FIRST_C_URL_BREAK_H

/**
 * URL
 */
typedef struct url {
    /**
     * 协议
     */
    char *protocol;
    /**
     * HOST
     */
    char *host;
    /**
     * 端口
     */
    int port;
    /**
     * 资源
     */
    char *resource;
} url;

/**
 * 根据链接返回一个url
 * @param link 链接
 * @return url指针
 */
url *create_url(char *link);

#endif //HEAD_FIRST_C_URL_BREAK_H
