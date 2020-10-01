#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
        int sd,b,len;
        char msg[100];
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("Enter the port no : ");
        int portno;
        scanf("%d",&portno);
        server.sin_port=htons(portno);
        server.sin_addr.s_addr=htonl(INADDR_ANY);

        //socket creation

        sd=socket(AF_INET,SOCK_DGRAM,0);
        if(sd==-1){
                printf("Socker=t creation failed\n");
                exit(0);
        }
        else{
                printf("Socket Created\n");
        }

        len=sizeof(server);
	printf("1-Add\n2-Subtract\n3-Product\n4-Quotient\nEnter your choice : ");
        scanf("%s",msg);
	sendto(sd,msg,100,0,(struct sockaddr*)&server,len);
	//recvfrom(sd,msg,100,0,(struct sockaddr*)&server,&len);
	//printf("Server msge : %s ",msg);
	close(sd);
}
