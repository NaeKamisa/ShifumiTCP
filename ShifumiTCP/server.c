#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int main(){

    #define SERVER_PORT 3001
    int i = 0;
    int client_fd[0];
    int clients[BUFSIZ];
    int nb_clients = 0;
    int server_fd;
    int player = 0;

    server_fd = socket(AF_INET,SOCK_STREAM,0);perror("socket()");
    struct sockaddr_in addr ={
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(SERVER_PORT)
    };

    bind(server_fd,(struct sockaddr*)&addr,sizeof(addr));perror("bind()");

    listen(server_fd,BUFSIZ);perror("listen()");
    printf("Server listen to 127.0.0.1:%d\n",SERVER_PORT);
    struct sockaddr_in addrclient;
    socklen_t len;


    
    
    while (player < 2){

        client_fd[0] = accept(server_fd,(struct sockaddr*)&addrclient,&len);perror("accept()");
        if(client_fd != -1){
            char buf[BUFSIZ];memset(buf,0,BUFSIZ);
            printf("En attente des deux joueur",buf);
            send(client_fd,buf,BUFSIZ,0);perror("send()");
        }
        i++;
        player++;
        }
    while (i = 2){
        
    }




    close(client_fd);
    return 0;
}