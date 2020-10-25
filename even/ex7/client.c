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
        int sd,c,len;
        int msg,ack,size,nack=1;
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("Enter the port no : ");
        int portno;
        scanf("%d",&portno);
        server.sin_port=htons(portno);
        server.sin_addr.s_addr=htonl(INADDR_ANY);

        //socket creation

        sd=socket(AF_INET,SOCK_STREAM,0);
        if(sd==-1){
                printf("Socker=t creation failed\n");
                exit(0);
        }
        else{
                printf("Socket Created\n");
        }

        //connection establishment

        len=sizeof(server);
        c=connect(sd,(const struct sockaddr*)&server,len);
        if(c==-1){
                printf("Connection failed\n");
                exit(0);
        }
        else{
                printf("Connection established\n");
	}
	while(1){
		read(sd,&msg,sizeof(int));
		size++;
		printf("The data is : %d",msg);
		printf("1-No ACK\n2-Normal ACK\n3-NACK\nEnter you choice : ");
		scanf("%d",&ack);
		switch(ack){
			case 1:
			case 2:
				ack=size;
				write(sd,&ack,sizeof(int));
				break;
			case 3:
				if(nack==1)
					write(sd,&nack,sizeof(int));
				else{
					nack++;
					write(sd,&nack,sizeof(int));
				}
				size--;
				break;
		}
