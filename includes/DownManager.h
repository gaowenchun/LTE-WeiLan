#include <iostream>
#include <cstdio>
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
#include "../includes/sqlite3.h"
#include "../includes/log.h"

#define BUFFERLEN 1024
#define CMCCIP "192.168.1.90"
#define CUCCIP "192.168.1.91"
#define CTCCIP "192.168.1.92"

using namespace std;
void startcell(int ufd, char* IP);

void down_send(int ufd,struct sockaddr_in &address,char* IP,char* sendbuf);

int parsedownMessage(char* recvbuf,char* sendbuf,char* sendip);

int thread_down(int* msock_fd);
