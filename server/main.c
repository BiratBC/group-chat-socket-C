#include "socketutil.h"

int main()
{

    int serverSocketFD = createTCPIpv4Socket();

    // this will be the host address of this server
    struct sockaddr_in *serverAddress = createIpv4Addrress("", 2000);

    // bind the address to the socket for the server to listen for connections
    // whatever the address and port we bind the server will listen for that address and port from the upcomming connections from users or client
    int result = bind(serverSocketFD, (struct sockaddr *)serverAddress, sizeof(*serverAddress));
    if (result == 0)
    {
        printf("Socket was bound successfully\n");
    }

    // listen to the upcoming connections
    //  10 connections will be in queue
    int listenResult = listen(serverSocketFD, 10);

    // accept will create a file descriptor for each connecting client on the server side and returns the file descriptor ,
    //  so we will have the access to the file descriptor of client on server side

    struct sockaddr_in clientAddress;
    int clientAddressSize = sizeof(clientAddress);
    // accept will wait for a client connection to be made
    int clientSocketFD = accept(serverSocketFD, (struct sockaddr *)&clientAddress, &clientAddressSize);

    // Message incoming

    char buffer[1024];
    while (1)
    {
        ssize_t amountReceived = recv(clientSocketFD, buffer, 1024, 0);
        if (amountReceived > 0)
        {   
            buffer[amountReceived] = 0; //resetting the buffer for next info
            printf("Response we receive: %s\n", buffer);
        }
        if (amountReceived == 0)
        {
            break;
        }
        
    }

    close(clientSocketFD);
    shutdown(serverSocketFD, SHUT_RDWR); //shut down read and write

    return 0;
}