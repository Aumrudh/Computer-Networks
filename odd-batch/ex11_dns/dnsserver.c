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
	struct servent *serv;
	struct in_addr ipv4addr;	
	struct hostent *host;
	struct in_addr ip_addr;
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
	if((b = bind(sd,(struct sockaddr *) &server,sizeof(server))) == -1)
	{
		printf("\n> Socket isnot associated with port...\n");
		exit(1);
	}
	else
	{
		printf("\n> Socket associated with port...\n");
	}
	printf("\n> DNS Server Started...\n");
	printf("\n> Connection Done!...\n");
	len = sizeof(server);
	do{
		recvfrom(sd,&choice,sizeof(int),0,(struct sockaddr *) &server,&len);
               if(choice == 1)
	       {
			char service[25]={0};
			int port;
			recvfrom(sd,&port,sizeof(int),0,(struct sockaddr *) &server,&len);
			recvfrom(sd,service,50,0,(struct sockaddr *) &server,&len);
			if ((serv = getservbyport(htons(port), service)) != NULL)
				sendto(sd,serv->s_name,50,0,(struct sockaddr*)&server,len);
			else
				sendto(sd,"Service Not Found",50,0,(struct sockaddr*)&server,len);
		}
	       else if(choice == 2)
	       {
			char h_name[25]={0};
			recvfrom(sd,h_name,50,0,(struct sockaddr *) &server,&len);
			if ((host = gethostbyname(h_name)) == NULL)
				sendto(sd,"IP Not Resolved",50,0,(struct sockaddr*)&server,len);
			else
			{
				ip_addr = *(struct in_addr *)(host->h_addr);
				sendto(sd,inet_ntoa(ip_addr),50,0,(struct sockaddr*)&server,len);
			}
	       }
	        else if(choice == 3)
		 {
			close(sd);
			exit(1);
		}
	       else
			printf("\n> Invalid Option...\n");
		sendto(sd,msg,50,0,(struct sockaddr *) &server,len);
	}while(1);
}
