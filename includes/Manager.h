/************************************************************************
 ** Author: ICT
 ** Data:2017-1-20
 **
 ************************************************************************/
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <pthread.h>
#include <assert.h>
#include "sqlite3.h"
#include "TransmitFIFO.h"
#define MAXBUF 4096
using namespace std;

void InitFIFO();
int thread_down(int* msock_fd);
int thread_up(int *msock_fd);
void POll_write(int* msock_fd);
void pthread_handle_up_message(int* msock_fd);

void tcp_data_packing(unsigned char* Send_Buf,char* buf);

#endif

