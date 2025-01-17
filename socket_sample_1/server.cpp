// Server side C/C++ program to demonstrate Socket programming in linux/mac
// gcc server.cpp -o server
///////////////////////////

#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include <unistd.h>

#define PORT 8080


int main(int argc, char* argv[]){

    int server_fd, new_socket, valread;

    sockaddr_in address;
    int opt =1;
    int addrlen=sizeof(address);
    char buffer[1024]={0};
    char * hello=(char*)"Hello From Server";

    //create socket file descriptior

    if((server_fd=socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("Socket creation failed \n");
        exit( EXIT_FAILURE);
    };

    // forcfully attaching the socket to port 8080
    if(setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR, &opt,sizeof(opt))){
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family=AF_INET;
    address.sin_addr.s_addr=INADDR_ANY;
    address.sin_port=htons(PORT);

    // Forcefully attaching socket to the port 8080
    if(bind(server_fd,(struct sockaddr*)&address,sizeof(address)) < 0){
        perror("Socket bind failed \n");
        exit(EXIT_FAILURE);
    }
    if(listen(server_fd,3)<0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if((new_socket=accept(server_fd,(struct sockaddr*)&address,(socklen_t*) &addrlen))< 0){
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread=read(new_socket,buffer,1024);
    printf("%s \n",buffer);

    send(new_socket,hello,strlen(hello),0);
    printf("Hello message sent \n");

    // close new socket
    close(new_socket);

    //shutdown
    shutdown(server_fd,SHUT_RDWR);

    return 0;

}
