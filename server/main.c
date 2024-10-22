#include "include.h"

int main()
{
    // создам сокет сервера
    create_server();

    // 6.читаем Сообщение от клиента и заполняем буффер
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Сообщение от клиента: %s\n", buffer);

    send(new_socket, response, strlen(response), 0);
    printf("Сообщение клиенту отправлено\n");

    // закрываем сокеты
    close_sockets();

    return 0;
}
