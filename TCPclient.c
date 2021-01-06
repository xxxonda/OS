#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){
        //create socket
        int network_socket;//socket descriptor
        network_socket = socket(AF_INET, SOCK_STREAM, 0 );
        
        //specify an adress
        struct sockaddr_in server_adress;
        server_adress.sin_family = AF_INET;
        server_adress.sin_port = htons(9002);//port
        server_adress.sin_addr.s_addr = INADDR_ANY;//inet_addr("192.168.0.100");

        int connection_status = connect(network_socket, (struct sockaddr *) &server_adress, sizeof(server_adress));
        if (connection_status == -1){
            printf("Trouble with connecting to the remote socket");
        }
        //recieve data from server
        char server_response[256];
        recv(network_socket, &server_response, sizeof(server_response), 0);

        //printout check
        printf("The server sent the data:%s\n", server_response);
        int close_status = close(network_socket);
        if (close_status == -1){
            printf("Error in closing the connection");
        }

        return 0;
}

