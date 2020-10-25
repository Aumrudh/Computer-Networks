#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

struct node{
	char src[5];
	char dst[5];
	int length;
}obj[10],temp[20],perm[4];

int main(){
        int sd,b,l,ad,len;
        char msg[100];
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("Enter the port no : ");
        int portno;
        scanf("%d",&portno);
        server.sin_port=htons(portno);
        server.sin_addr.s_addr=htonl(INADDR_ANY);

        //socket creation
	int matrix[4][4];
	printf("Enter the distance between each rows and columns");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%d",&matrix[i][j]);
			obj[j].src=i;
			obj[j].dst=j;
			obj[j].length=matrix[i][j];
		}

	}
        sd=socket(AF_INET,SOCK_STREAM,0);
        if(sd==-1){
                printf("Socker=t creation failed\n");
                exit(0);
        }
        else{
                printf("Socket Created\n");
        }

        //binding

        b=bind(sd,(struct sockaddr *)&server,sizeof(server));

        if(b==-1){
                printf("Binding failed\n");
                exit(0);
        }
        else{
                printf("Binded\n");
        }

        //listen

        l=listen(sd,5);
        if(l==-1){
                printf("Listen failed\n");
                exit(0);
        }
        else{
                printf("Listening\n");
        }

        //accept

        len=sizeof(client);
        ad=accept(sd,(struct sockaddr*)&client,&len);
        if(ad==-1){
                printf("Accept failed\n");
                exit(0);
        }
        else{
                printf("Accepted\n");
        }
        printf("Connection established\n");

