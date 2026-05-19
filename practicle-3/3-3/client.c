#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {

    int sockfd;

    struct sockaddr_in server_addr;

    char buffer[1024];

    // создание сокета
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {

        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // IP сервера
    if (inet_pton(AF_INET,
                  "127.0.0.1",
                  &server_addr.sin_addr) <= 0) {

        perror("inet_pton");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // connect
    if (connect(sockfd,
                (struct sockaddr*)&server_addr,
                sizeof(server_addr)) < 0) {

        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // recv
    ssize_t bytes_received =
            recv(sockfd,
                 buffer,
                 sizeof(buffer) - 1,
                 0);

    if (bytes_received < 0) {

        perror("recv");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0';

    printf("Received from server: %s\n", buffer);

    close(sockfd);

    return 0;
}