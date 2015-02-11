/*
 * p71
 * 书中只给出了部分代码示例
 * 我自己编写了IPv6以及Unix域套接字的相关代码
 * 可能有错误
 */
#include "unp.h"
char * sock_ntop(const struct sockaddr *sa,socklen_t salen){
    char portstr[8];
    static char str[128]; /* Unix domain is largest */

    switch(sa->sa_family){
        case AF_INET:{
            struct sockaddr_in *sin = (struct sockaddr_in*)sa;

            if(inet_ntop(AF_INET,&sin->sin_addr,str,sizeof(str))==NULL)
                return NULL;
            if(ntohs(sin->sin_port)!=0){
                snprintf(portstr,sizeof(portstr),":%d",ntohs(sin->sin_port));
                strcat(str,portstr);
            }
        }

        //自己编写的AF_INET6
        case AF_INET6:{
            struct sockaddr_in6 *sin6 = (struct sockaddr_in6*)sa;

            if(inet_ntop(AF_INET6,&sin6->sin6_addr,str,sizeof(str))==NULL)
                return NULL;
            if(ntohs(sin6->sin6_port)!=0){
                snprintf(portstr,sizeof(portstr),":%d",ntohs(sin6->sin6_port));
                strcat(str,portstr);
            }
        } 

        //自己编写的AF_UNIX
        case AF_UNIX:{
            struct sockaddr_un *sun = (struct sockaddr_un *)sa;
            
            strcpy(str,sun->sun_path);
        }
        return str;
    }
}

