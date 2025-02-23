#include "socketutil.h"
#include "main.h"
#include <unistd.h>
#include <pthread.h>

struct AcceptanceSocket
{
    int acceptedSocketFD;
    struct sockaddr_in address;
    int error;
    bool acceptedSuccessfully;
};
struct AcceptanceSocket acceptedSocket[10];
int acceptedSocketsCount = 0;
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

    struct AcceptanceSocket *clientSocket = acceptIncomingConnection(serverSocketFD);
    int clientSocketFD = clientSocket->acceptedSocketFD; // Extract the integer file descriptor

    // int clientSocketFD = acceptIncomingConnection(serverSocketFD);

    // This will start accepting connections in separate thread we create thread inside this function
    // startAcceptingIncomingConnections((void *)&serverSocketFD);
    pthread_t acceptThread;
    pthread_create(&acceptThread, NULL, startAcceptingIncomingConnections, (void *)&serverSocketFD);
    pthread_detach(acceptThread);

    while (1)
    {
        sleep(1); // Keep main alive
    }

    // Message incoming
    // receiveAndPrintIncomingData((void *)&clientSocketFD);

    shutdown(serverSocketFD, SHUT_RDWR); // shut down read and write

    return 0;
}
struct AcceptanceSocket *acceptIncomingConnection(int serverSocketFD)
{
    struct sockaddr_in clientAddress;
    int clientAddressSize = sizeof(clientAddress);

    printf("Waiting for a client to connect...\n");
    // accept will wait for a client connection to be made
    int clientSocketFD = accept(serverSocketFD, (struct sockaddr *)&clientAddress, &clientAddressSize);

    struct AcceptanceSocket *acceptanceSocket = malloc(sizeof(struct AcceptanceSocket));
    acceptanceSocket->address = clientAddress;
    acceptanceSocket->acceptedSocketFD = clientSocketFD;
    acceptanceSocket->acceptedSuccessfully = clientSocketFD > 0;

    if (!acceptanceSocket->acceptedSuccessfully)
    {
        acceptanceSocket->error = clientSocketFD;
    }
    return acceptanceSocket;
}
void *receiveAndPrintIncomingData(void *arg)
{
    int clientSocketFD = *(int *)arg;
      free(arg);
    char buffer[1024];
    printf("Listening for messages from client FD: %d...\n", clientSocketFD);
    while (1)
    {
        ssize_t amountReceived = recv(clientSocketFD, buffer, sizeof(buffer) - 1, 0);
        if (amountReceived > 0)
        {
            buffer[amountReceived] = 0;
            printf("Received: %s\n", buffer);

            sendReceivedMessageToTheOtherClient(buffer, clientSocketFD);
        }
        else if (amountReceived == 0)
        {
            printf("Client disconnected\n");
            break;
        }
        else
        {
            perror("recv failed\n");
            break;
        }
    }
    close(clientSocketFD);
    // free(arg);
    return NULL;
}

void *startAcceptingIncomingConnections(void *arg)

{

    int serverSocketFD = *(int *)arg;
    // to accept multiple connections we will use while loop
    while (1)
    {
        struct AcceptanceSocket *clientSocket = acceptIncomingConnection(serverSocketFD);
        // gatherting all the accepted socket

        acceptedSocket[acceptedSocketsCount++] = *clientSocket;

        // receiveAndPrintIncomingDataOnSeparateThread(clientSocket);
        // if (!clientSocket->acceptedSuccessfully)
        // {
        //     perror("Accept failed\n");
        //     printf("Accept Failed\n");
        //     free(clientSocket);
        //     continue;
        // }
        receiveAndPrintIncomingDataOnSeparateThread(clientSocket);
        // free(clientSocket); // Free memory after passing to the thread
    }
    // void * pointer must return some address
    return NULL;
    // //Each connection in separate thread
    // pthread_t id; // thread id
    // // Creating a new thread to isolate from main thread
    // pthread_create(&id, NULL, acceptNewConnectionAndReceiveAndPrintItsData, (void*)&serverSocketFD);
}

void receiveAndPrintIncomingDataOnSeparateThread(struct AcceptanceSocket *clientSocket)
{
    pthread_t id;
    int *clientFD = malloc(sizeof(int));
    *clientFD = clientSocket->acceptedSocketFD;
    printf("Starting thread for client FD: %d\n", *clientFD);
    fflush(stdout);
    pthread_create(&id, NULL, receiveAndPrintIncomingData, (void*)clientFD);
    pthread_detach(id);
    // free(clientSocket);
}

void sendReceivedMessageToTheOtherClient(char *buffer, int socketFD)
{
    for (int i = 0; i < acceptedSocketsCount; i++)
    {
        if (acceptedSocket[i].acceptedSocketFD != socketFD)
        {
            send(acceptedSocket[i].acceptedSocketFD, buffer, strlen(buffer), 0);
        }
    }
}