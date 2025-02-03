
#include "socketutil.h"

int createTCPIpv4Socket(){
    //three params (domain/address family(ip4/ip6), type of socket(sock stream for tcp), protocol(for the protocol level)'0' means the socket will select a default protocol for the requested socket type and domain)
    return socket(AF_INET,SOCK_STREAM,0);
}
struct sockaddr_in* createIpv4Addrress(char* ip, unsigned int port){
    //Creating an IP address
    struct sockaddr_in* address = malloc(sizeof(struct sockaddr_in)); //malloc to restrict overriden of data in the memory
    address->sin_port = htons(port); //endian transform 
    address->sin_family = AF_INET;
    //converting ip in string to binary form
    inet_pton(AF_INET,ip,&address->sin_addr.s_addr);
    return address;
}