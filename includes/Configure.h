//#ifndef _CONFIGURE_H
//#define _CONFIGURE_H

#include"sqlite3.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define Control_dB "../Database/Configure.db"

extern int tcp_port;
extern int udp_port;
extern char tcp_addr[256];
extern char udp_addr[256];

class sock_fd
{
public:
    int tcp_fd;
    int udp_fd;
};

class ControlManager {
public:
    ControlManager(int udpport,char* udp_adr,int tcpport,char* tcp_adr)
    {
        UDPPORT = udpport;
        memset(udp_address,'\0',sizeof(udp_address));
        memcpy(udp_address,udp_adr,strlen(udp_adr));
        TCPPORT = tcpport;
        memset(tcp_address,'\0',sizeof(tcp_address));
        memcpy(tcp_address,tcp_adr,strlen(tcp_adr));
    };
    ControlManager(){};
    int setnonblocking(int sockfd);
    int init_udp();
    int init_tcp();
    
private:
    int UDPPORT;
    int TCPPORT;
    char tcp_address[256];
    char udp_address[256];
};
 
int Control_Config();

//#endif
