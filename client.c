#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035
int main()
{
       int sockfd,n;
       struct sockaddr_in serv_addr;
       struct hostent *server;
       char buffer[4096];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       if(sockfd!=0)
	       printf("\nsocket created");
	else
		printf("\nSocket failed");
       serv_addr.sin_family=AF_INET;
      serv_addr.sin_addr.s_addr=INADDR_ANY;
       serv_addr.sin_port=htons(n);
       printf("\nenter port num: ");
       scanf("%d",&n);
       printf("\nReady for sending...");
       int cc=connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
        if(cc!=0)
		               printf("\nconneced");
	        else
			                printf("conect failed");
       printf("\nEnter the message to send : ");
       printf("\nClient: ");
       fgets(buffer,4096,stdin);
       write(sockfd,buffer,4096);
       printf("Serverecho:%s",buffer);
       printf("\n");
       close(sockfd);
       return 0;
}

