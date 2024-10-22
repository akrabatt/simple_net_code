#include "include.h"

void create_server()
{
    // 1.создаем сокет сервера
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Ошибка создания сокета");
        exit(EXIT_FAILURE);
    }

    // 2.настраиваем пар-ры сокета
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // принять подключение от любого ip адресса
    address.sin_port = htons(PORT); // переводим биты в другую последовательность htons
    
    // 3.привязываем сокет к порту
    if(bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("Ошибка привязки привязки сокета\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 4.начинаем слушать подключения 
    if(listen(server_fd, CLIENTS_) < 0)
    {
        perror("Ошибка прослушивания\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }    

    printf("Сервер запущен и ожидает подключения клиента...\n");

    // 5.ожидаем подключения клиента
    if((new_socket = accept(server_fd, (struct sockaddr* )&address, (socklen_t*)&addrlen)) < 0)
    {
        perror("Ошибка при принятии подключения\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
}
