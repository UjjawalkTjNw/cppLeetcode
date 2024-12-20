#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int PORT = 8080;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = PORT;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the host address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    // Listen for clients
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept connection from a client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("ERROR on accept");

    // Clear the buffer
    bzero(buffer, 256);

    // Read client's message
    n = read(newsockfd, buffer, 255);
    if (n < 0) error("ERROR reading from socket");

    // Print client's message
    printf("Here is the message: %s\n", buffer);

    // Reply to client
    n = write(newsockfd, "I got your message", 18);
    if (n < 0) error("ERROR writing to socket");

    // Close sockets
    close(newsockfd);
    close(sockfd);
    return 0; 
}
