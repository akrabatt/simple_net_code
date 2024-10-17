#include "include.h"
#include "define.h"

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char* response = "Сообщение получено сервером\n";
}
