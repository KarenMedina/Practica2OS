#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 3535

int main(int argc, char *argv[]){

time_t tiempo_inicio, tiempo_final;
double segundos;
int clientfd,r;
struct sockaddr_in client;
struct hostent *he;
char buffer[atoi(argv[2])+1];
clientfd = socket(AF_INET, SOCK_STREAM, 0);
tiempo_inicio = clock();

if(clientfd<0){
	perror("error en socket");
	exit(-1);
}
client.sin_family = AF_INET;
client.sin_port = htons(PORT);
inet_aton(argv[1], &client.sin_addr);

r= connect(clientfd, (struct sockaddr*)&client, (socklen_t)sizeof(struct sockaddr));
if(r<0){
	perror("error en connect");
	exit(-1);
}
r= recv(clientfd, buffer, atoi(argv[2]), 0);
if(r<0){
	perror("error en recv");
	exit(-1);
}
buffer[r]=0;
printf("\n Mensaje: %s", buffer);
//printf("%d", sizeof(buffer), "%d", sizeof(r));
close(clientfd);
tiempo_final = clock();

segundos = (double)(tiempo_final - tiempo_inicio ) / CLOCKS_PER_SEC; /*según que estes midiendo el tiempo en segundos es demasiado grande*/

printf("\nLa operación leyo %d kb de datos en %f", atoi(argv[2]), segundos);

}
