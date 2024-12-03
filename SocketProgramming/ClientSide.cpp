#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

const int PORT = 8080;

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    portno = PORT;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Get the server by its address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Initialize server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // Clear the buffer and get user input
    bzero(buffer, 256);
    printf("Please enter the message: ");
    fgets(buffer, 255, stdin);

    // Send message to server
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");

    // Clear buffer and read server's response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) 
         error("ERROR reading from socket");

    // Print server's response
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);
    return 0;
}
