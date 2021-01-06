#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
int main(){
int server_socket;//socket descriptor
server_socket = socket(AF_INET, SOCK_STREAM, 0 );
        
        //specify an adress
        struct sockaddr_in server_adress;
        server_adress.sin_family = AF_INET;
        server_adress.sin_port = htons(9002);//port
        server_adress.sin_addr.s_addr = INADDR_ANY;//inet_addr("192.168.0.100");

        bind(server_socket, (struct sockaddr*) &server_adress, sizeof(server_adress));
        
        listen(server_socket, 5);

        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);
        char server_message[256] = {"Hello there"};

        send(client_socket, server_message, sizeof(server_message), 0);

        close(server_socket);
        return 0;
}