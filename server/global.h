#ifndef GLOBAL_H
#define GLOBAL_H

#include "define.h"
extern int server_fd;                     // сокет для сервера
extern int new_socket;                    // сокет для клиента
extern struct sockaddr_in address;        // структура адресса сокета
extern int addrlen;                       // размер структура даресса серевера
extern char buffer[BUFFER_SIZE];          // буффер для входящих сообщений
extern char* response;                    // ответ сервера


#endif // GLOBAL_H
