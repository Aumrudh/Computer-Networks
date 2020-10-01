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
	int sd,b,l,ad,len;
	char msg[100],result[100];
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
	do{
		recv(ad,msg,100,0);
		printf("Client side : %s\n",msg);
		int i=0;
		int j=strlen(msg)-1;
		while(j>i){
			if(msg[i++]!=msg[j--]){
				strcpy(result,msg);
				strcat(result," is not palindrome!");
				break;
			}
			strcpy(result,msg);
			strcat(result," is Palindrome!");
		}
		//scanf("%s",msg);
		send(ad,result,100,0);
	}while(strcmp(msg,"bye")!=0);
	close(sd);
}	

