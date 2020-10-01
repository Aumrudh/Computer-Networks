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
        int sd,b,len,len1,len2;
	pid_t p1;
        char msg[100];
        struct sockaddr_in server,client,c3,c4;
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
	//len1=sizeof(c3);
	//len2=sizeof(c4);
	int i=0,n1,n2,c,ans=0;
	char msge1[100],msge2[100];//,sum[100],dif[100],pdt[100],quo[100];
	while(i<=3){
		p1=fork();
		if(p1 == 0){
			//printf("inside child\n");
			if(i==0){   //client1	
				recvfrom(sd,msg,100,0,(struct sockaddr*)&client,&len);
				strcpy(msge1,msg);
				n1=atoi(msg);
				printf("1st Client Message : %s \n",msg);
				i++;
			}
			if(i==1){   //c2
                                recvfrom(sd,msg,100,0,(struct sockaddr*)&client,&len);
                                strcpy(msge2,msg);
				n2=atoi(msg);
                                printf("2nd Client Message : %s \n",msg);
                        	i++;
			}
			if(i==2){  //c3
				recvfrom(sd,msg,100,0,(struct sockaddr*)&client,&len);
				printf("3rd Client Message : %s \n",msg);
				c=atoi(msg);
				if(c==1){
					ans=n1+n2;
					//printf("%d",ans);
				}
				else if(c==2){
					ans=n1-n2;
					//printf("%d",ans);
				}	
				else if(c==3){
					ans=n1*n2;
				//	printf("%d",ans);
				}
				else if(c==4){
					ans=n1/n2;
				//	printf("%d",ans);
				}
				else{}
				i++;
				//sprintf(msg,"%d",ans);
                                //sendto(sd,msg,100,0,(struct sockaddr*)&client,len);
			}
			if(i==3){ //c4
				recvfrom(sd,msg,100,0,(struct sockaddr*)&client,&len);
				printf("4th client msge : %s",msg);
				sprintf(msg,"%d",ans);
				sendto(sd,msg,100,0,(struct sockaddr*)&client,len);
				i++;
				close(sd);
			}
		}
		if(p1>0){
			wait();
		}
	}
	//   	close(sd);
}

