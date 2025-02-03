
#include "socketutil.h"

int main(){


    int socketFD =  createTCPIpv4Socket(); //Creating a socket

    //Here the retured value "address" is a pointer to the sockaddr_in (
    struct sockaddr_in *address = createIpv4Addrress("172.253.63.100",80); //Creating a ip address for that socket to connect

    //Connecting the client socket with server suing file descriptor and address
    // int result = connect(socketFD,(struct sockaddr*)&address, sizeof address);

    int result = connect(socketFD, (struct sockaddr*)address, sizeof(*address)); //connect() method strictly requires sockaddr type of address so we hve to typecast the sockaddr_in address (which is for ipv4) to sockaddr

    //0-> success, -1-> unsuccess
    if (result == 0)
    {
        printf("Connection Successfull\n");
    }    
    else{
        printf("Connection failed\n");
    }
    
    char* message; //creating message (string)
    //sending buffer(message) to the socket file decriptor
    //get the root page of google using http request
    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";

    //SEND
    send(socketFD,message, strlen(message), 0);

    char buffer[1024]; //creating a buffer (buffer holds the server response here) to receive the response which we get from server(google);
    //RECEIVE
    recv(socketFD, buffer, 1024, 0);

    // printf("Response we receive: %s\n", buffer);

    return 0;
}
