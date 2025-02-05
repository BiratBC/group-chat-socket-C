#ifndef SOCKETUTIL_SOCKETUTIL_H
#define SOCKETUTIL_SOCKETUTIL_H

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<unistd.h>

int createTCPIpv4Socket();
struct sockaddr_in* createIpv4Addrress(char* ip, unsigned int);

#endif 