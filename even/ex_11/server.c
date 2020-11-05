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

        //binding

        b=bind(sd,(struct sockaddr *)&server,sizeof(server));

        if(b==-1){
                printf("Binding failed\n");
                exit(0);
        }
        else{
                printf("Binded\n");
        }
        len=sizeof(client);
        do{
                recvfrom(sd,msg,100,0,(struct sockaddr*)&client,&len);
                printf("Client message : %s\n",msg);
                int cm=atoi(msg);
                char temp[100];
                if(cm==1){                 
                  recvfrom(sd,msg,100,0,(struct sockaddr*)&client,&len);
                  printf("Client message : %s\n",msg);
                  struct hostent *he;
                  struct in_addr addr;
                  addr.s_addr = inet_addr(msg);
                  he = gethostbyaddr((char *)&addr, sizeof(addr), AF_INET);
                  strcpy(temp,he->h_name);
                  printf("host name : %s ",temp);
                  sendto(sd,temp,100,0,(struct sockaddr*)&client,sizeof(client));
                }
                if(cm==2){
                  char f1[100];
                  recvfrom(sd,msg,100,0,(struct sockaddr*)&client,&len);
                  printf("Client message : %s\n",msg);
                  strcpy(f1,msg);
                  recvfrom(sd,msg,100,0,(struct sockaddr*)&client,&len);
                  printf("Client message : %s\n",msg);
                  struct servent* s = getservbyname(f1,msg);//"telnet", "tcp");
                  int t=ntohs(s->s_port);
                  printf("Port no : %d ",t);
                  sprintf(temp,"%d",t);
                  sendto(sd,temp,100,0,(struct sockaddr*)&client,sizeof(client));
                }
                
        }while(strcmp(msg,"bye")!=0);
        close(sd);
}

