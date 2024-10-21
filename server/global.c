#include "include.h"

int server_fd;                      // сокет сервера
int new_socket;                     // сокет клиента               
struct sockaddr_in address;         // структура адресса сокета
int addrlen = sizeof(address);      // размер структура адресса сервера
char buffer[BUFFER_SIZE] = {0};     // буффер для входящих сообщений
char* response = "Сообщение получено сервером\n";    // ответ сервера
