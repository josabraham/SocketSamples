
//Example code: A simple server side code, which echos back the received message.
//Handle multiple socket connections with select and fd_set on Linux 

#include <stdio.h>
#include <string.h> //strlen 
#include <stdlib.h>
#include <errno.h>
#include <unistd.h> //close 
#include <arpa/inet.h> //close 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros 

#define TRUE 1
#define FALSE 0
#define PORT 8888

int main(int argc , char *argv[]){

    int opt = TRUE;

    int master_socket, addr_len, new_socket, client_socket[30],
                max_clients = 30, i, val_read,sd;

    int max_sd;
    struct sockaddr_in address;

    char buffer[1025];//data buffer of 1K 

    return 0;
}

