#ifndef _UNP_H
#define _UNP_H

#include "../config.h"
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXLINE    4096
#define BUFFSIZE   8192

/**
 * 自定义的头文件
 */
char *sock_ntop(const struct sockaddr *sa,socklen_t salen);
ssize_t readn(int fd,void *vptr,size_t n);
ssize_t writen(int fd,void *vptr,size_t n);
ssize_t readline(int fd,void *vptr,size_t maxlen);
#endif
