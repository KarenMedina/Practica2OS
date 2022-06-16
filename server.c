#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h> 

#define PORT 3535
#define BACKLOG 8

int main(int argc, char *argv[]){
FILE *fp;
fp  = fopen ("data.log", "w");
 
int serverfd, clientfd, r;
struct sockaddr_in server, client;
socklen_t socklen;
int castT = atoi(argv[1]);
char buffer[castT+1];
buffer[0]="c";
int i;


serverfd=socket(AF_INET, SOCK_STREAM, 0);
if (serverfd <0){
	perror("error en socket");
	exit(-1);
}
server.sin_family=AF_INET;
server.sin_port= htons(PORT);
server.sin_addr.s_addr= INADDR_ANY;
bzero(server.sin_zero, 8);

r=bind(serverfd, (struct sockaddr*)&server, sizeof(struct sockaddr));
if(r<0){
	perror("error en bind");
	exit(-1);
}
r= listen(serverfd, BACKLOG);
if(r<0){
	perror("error en listen");
	exit(-1);
}
clientfd = accept(serverfd, (struct sockaddr*)&client, &socklen);
if(r<0){
	perror("Error en accept");
	exit(-1);
}
for(i =1; i < atoi(argv[1]); i++){
	strncat(buffer, "c",1);
}
r= send(clientfd, buffer, castT, 0);
if(r<0){
	perror("error en send");
	exit(-1);
}
printf("\n Mensaje: %s", buffer);
fprintf(fp, buffer, "\n");

close(clientfd);
close(serverfd);
}
