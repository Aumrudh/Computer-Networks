#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define PORT 8888
#define SA struct sockaddr
int main()
{
       int sockfd,n,f=0,try=0;
       struct sockaddr_in serv_addr;
       struct hostent *server;
       char buffer[4096],buf[4096],user[10],pass[10],msg[50]="fail",com[50];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       if(sockfd==-1)
       {
               printf("Socket creation failed..\n");
       }
       else
       {
               printf("Socket created..\n");
        }
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=(INADDR_ANY);
       serv_addr.sin_port=htons(PORT);
       if(connect(sockfd,(SA*)&serv_addr,sizeof(serv_addr))!=0)
       {
               printf("Connection with server failed..\n");
       }
       else
       {
               printf("Connected to server..\n");
        }
       for(;;)
       {
       printf("Enter your username:\t");
       scanf("%s",user);
       printf("Enter password:\t");
       scanf("%s",pass);
       strcat(com,user);
       strcat(com,"_");
       strcat(com,pass);
       printf("com:%s",com);
       send(sockfd,com,sizeof(com),0);
       strcpy(com,"\0");
       recv(sockfd,buffer,sizeof(buffer),0);
       printf("\n%s\n\n",buffer);
       if(strcmp(buffer,"fail")==0)
	       exit(0);
       strcpy(buffer,"");
       recv(sockfd,buffer,sizeof(buffer),0); 
       printf("%s\n\n",buffer);
      }
       close(sockfd);
       return 0;
}
