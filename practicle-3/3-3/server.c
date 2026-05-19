#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {

    int server_fd;
    int client_fd;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    socklen_t client_len = sizeof(client_addr);

    // создание сокета
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // настройка адреса
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind
    if (bind(server_fd,
             (struct sockaddr*)&server_addr,
             sizeof(server_addr)) < 0) {

        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // listen
    if (listen(server_fd, 5) < 0) {

        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is waiting on port %d...\n", PORT);

    // accept
    client_fd = accept(server_fd,
                       (struct sockaddr*)&client_addr,
                       &client_len);

    if (client_fd < 0) {

        perror("accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // сообщение
    const char *message = "Hello from server";

    // send
    if (send(client_fd,
             message,
             strlen(message),
             0) < 0) {

        perror("send");
    }

    printf("Message sent to client.\n");

    close(client_fd);
    close(server_fd);

    return 0;
}