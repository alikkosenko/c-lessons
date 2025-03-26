// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;

    // Обрабатываем сообщения клиента
    while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0'; // добавляем завершающий нулевой символ
        printf("Client: %s\n", buffer);
        send(client_socket, buffer, strlen(buffer), 0); // отправляем обратно клиенту
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Создаем сокет
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Привязываем сокет к адресу
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Начинаем слушать
    if (listen(server_socket, 3) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Принимаем подключения
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) > 0) {
        printf("Connection established with client\n");
        handle_client(client_socket);
    }

    if (client_socket == -1) {
        perror("Accept failed");
    }

    close(server_socket);
    return 0;
}

