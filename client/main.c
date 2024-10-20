#include "define.h"
#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message_for_server [MESSAGE_FOR_SERVER] = {0};
    char buffer[BUFFER_SIZE] = {0};
    char ip_addr[IP_ADDR_LEN] = {0};

    // 1.создаем сокет для клиента
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Ошибка соединения сокета\n"); 
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    printf("Введите ip адресс сервера: ");
    fgets(ip_addr, IP_ADDR_LEN, stdin);
    ip_addr[strcspn(ip_addr, "\n")] = 0; // заменяем символ на нуль-терминатор 

    // 2.преобразуем IP-адресс и подключаемся к серверу
    if(inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) <= 0)
    {
        perror("Неверный адресс/адресс не поддерживается");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Ошибка подключения\n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Введите сообщение для сервера: ");
    fgets(message_for_server, MESSAGE_FOR_SERVER, stdin);

    // 3.Отправляем сообщение серверу
    send(sock, message_for_server, strlen(message_for_server), 0);
    printf("Сообщение отправлено\n");

    // 4.Ждем ответа от сервера
    read(sock, buffer, BUFFER_SIZE);
    printf("Ответ от сервера: %s\n", buffer);

    close(sock);

    return 0;
}
