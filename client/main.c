
#include "socketutil.h"

int main()
{

    int socketFD = createTCPIpv4Socket(); // Creating a socket

    // Here the retured value "address" is a pointer to the sockaddr_in (
    struct sockaddr_in *address = createIpv4Addrress("127.0.0.1", 2000); // Creating a ip address for that socket to connect

    // Connecting the client socket with server suing file descriptor and address
    //  int result = connect(socketFD,(struct sockaddr*)&address, sizeof address);

    int result = connect(socketFD, (struct sockaddr *)address, sizeof(*address)); // connect() method strictly requires sockaddr type of address so we hve to typecast the sockaddr_in address (which is for ipv4) to sockaddr

    // 0-> success, -1-> unsuccess
    if (result == 0)
    {
        printf("Connection Successfull\n");
    }
    else
    {
        printf("Connection failed\n");
    }

    // Read the input/message from the console
    char *line = NULL;
    size_t lineSize = 0;
    printf("Type to send the information : (type exit)\n");
    while (1)
    {
        ssize_t charCount = getline(&line, &lineSize, stdin);
        if (charCount > 0)
        {
            if (strcmp(line, "exit\n") == 0)
                break;
            ssize_t amountWasSent = send(socketFD, line, charCount, 0);
        }
    }

    close(socketFD);
    // char *message; // creating message (string)
    // // sending buffer(message) to the socket file decriptor
    // // get the root page of google using http request
    // message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";

    // // SEND
    // send(socketFD, message, strlen(message), 0);

    // char buffer[1024]; // creating a buffer (buffer holds the server response here) to receive the response which we get from server(google);
    // // RECEIVE
    // recv(socketFD, buffer, 1024, 0);

    // printf("Response we receive: %s\n", buffer);

    return 0;
}
