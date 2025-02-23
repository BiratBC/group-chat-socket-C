#pragma once
void* receiveAndPrintIncomingData(void *arg);
void* startAcceptingIncomingConnections(void* arg);
// void* acceptNewConnectionAndReceiveAndPrintItsData(void *arg);
struct AcceptanceSocket *acceptIncomingConnection(int serverSocketFD);
void receiveAndPrintIncomingDataOnSeparateThread(struct AcceptanceSocket* clientSocket);
void sendReceivedMessageToTheOtherClient(char *buffer, int socketFD);
