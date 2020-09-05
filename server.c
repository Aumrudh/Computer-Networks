#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h> 
int main()
{
       int sockfd,newsockfd,clength,n;
       struct sockaddr_in serv_addr,cli_addr;
       char buffer[4096];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       if(sockfd==-1)
	       printf("socket faild\n");
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=INADDR_ANY;
       printf("enter port num: ");
       scanf("%d",&n);
       serv_addr.sin_port=htons(n);
       printf("\nStart");
       int b=bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       if(b==-1)
	       printf("bind failed");
       printf("\nListening...");
       printf("\n");
       int lis=listen(sockfd,5);
        if(lis==-1)
		               printf("listen failed");
       clength=sizeof(cli_addr);
       newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
       if(newsockfd!=-1)
       printf("\nAccepted");
       printf("\n");
       read(newsockfd,buffer,4096);
       printf("\nClient message:%s",buffer);
       write(newsockfd,buffer,4096);
       printf("\n");
       close(sockfd);
       return 0;
}

