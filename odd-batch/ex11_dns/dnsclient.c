#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#define PORT 2301
int main()
{
	int sd,b,len,choice;
	char msg[50];
	struct sockaddr_in server,client;
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if((sd = socket(AF_INET,SOCK_DGRAM,0)) == -1)
	{
		printf("\n> Socket Creation Failed...\n");
		exit(1);
	}
	else
	{
		printf("\n> Socket created Successfully...\n");
	}
	printf("\n> DNS Client Started...\n");
	printf("\n> Connection Done!...\n");
	printf("\n> 1.getServByPort\n");
 	printf("\n> 2.getHostByName\n");
 	printf("\n> 3.Exit\n");
	len = sizeof(server);
        do
	{
		printf("\n> Enter Your choice: \t");
		scanf("%d",&choice);
		sendto(sd,&choice,sizeof(int),0,(struct sockaddr *) &server,len);
	        if(choice == 1)
		{
			char service[25]={0},domain[25]={0};
			int port;
			printf("\n> Enter the port Address: \t");
			scanf("%d",&port);
			printf("> Enter the Service: \t");
			scanf("%s",service);
			sendto(sd,&port,sizeof(int),0,(struct sockaddr *) &server,len);
			sendto(sd,service,50,0,(struct sockaddr *) &server,len);
			recvfrom(sd,domain,50,0,(struct sockaddr *) &server,&len);
			printf("\n> Name: %s",domain);
			printf("\n> Port: %d",port);
			printf("\n> Protocol: %s\n",service);
		}
		else if(choice == 2)
		{
			char h_name[25]={0},addr[25]={0};
			printf("\n> Enter the host name: \t");
			scanf("%s",h_name);
			sendto(sd,h_name,50,0,(struct sockaddr *) &server,len);
			recvfrom(sd,addr,50,0,(struct sockaddr *) &server,&len);
			printf("\n> Hostname: %s",h_name);
			printf("\n> IP Address: %s\n",addr);
		}
		else if(choice == 3)
		{
			close(sd);
			exit(1);
		}
		else
			printf("\n> Invalid Option...\n");
	}while(1);
}
