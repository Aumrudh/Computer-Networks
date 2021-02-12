#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#define SA struct sockaddr
#define PORT 8888

int logincheck(char idd[],char buf1[])
{
     char pass[10]={0},fid[10]={0},fpas[10]={0};
     strcpy(idd,strtok(buf1,"_"));
     strcpy(pass,strtok(NULL,"_"));
     FILE *f1=fopen("login.txt","r");
     while(!feof(f1))
     {
	fscanf(f1,"%s %s",fid,fpas);
	//printf("\nidd:%s\tpass:%s",fid,fpas);
        if((strcmp(idd,fid)==0) && (strcmp(pass,fpas)==0))
	{	 
		return 1;
	}
     }
     return 0;     
}

void facfile(char file[],char buf[])
{
	FILE *f2=fopen(file,"r");
	char c;
	while(fscanf(f2,"%c",&c)==1)
		strncat(buf,&c,1);
	buf[strlen(buf)]='\0';
	fclose(f2);
}

void stufile(char id[],char file[],char buf[]){
	FILE *f3=fopen(file,"r");
	char fid[10]={0},fname[10]={0},fm1[3]={0},fm2[3]={0},fm3[3]={0},fm4[3]={0},fm5[3]={0};
	while(!feof(f3))
	{
		fscanf(f3,"%s %s %s %s %s %s %s",fid,fname,fm1,fm2,fm3,fm4,fm5);
		if(strcmp(id,fid)==0)
		{
			strcat(buf,fid);
			strcat(buf," ");
			strcat(buf,fname);
			strcat(buf," ");
			strcat(buf,fm1);
			strcat(buf," ");
			strcat(buf,fm2);
			strcat(buf," ");
			strcat(buf,fm3);
			strcat(buf," ");
			strcat(buf,fm4);
			strcat(buf," ");
			strcat(buf,fm5);
		 }
	}
	buf[strlen(buf)]='\0';
}


int main()
{
       int sockfd,newsockfd,clength,n,b;
       struct sockaddr_in serv_addr,cli_addr;
       char buf[4096],c,idd[30],buf1[100];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       if(sockfd==-1)
       {
               printf("Socket creation failed..\n");
       }
       else
       {
               printf("Socket created successfully..\n");

        }
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
       serv_addr.sin_port=htons(PORT);
       if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))!=0)
       {
               printf("socket bind failed...\n");
       }
       else
       {
               printf("Socket binded \n");
        }
       if(listen(sockfd,5)!=0)
       {
               printf("Listen failed..\n");
       }
       else
       {
               printf("Listening..\n");
       }
       clength=sizeof(cli_addr);
       newsockfd=accept(sockfd,(SA*)&cli_addr,&clength);
       if(newsockfd<0)
       {
               printf("Srever accept failed...\n");
       }
       else
       {

        printf("Accepted...\n");
       }
       for(;;)
       {
       recv(newsockfd,buf1,sizeof(buf1),0);
       int k=logincheck(idd,buf1);
       if(k==1)
       {
	       strcpy(buf,"loged in..");
	       send(newsockfd,buf,sizeof(buf),0);
		strcpy(buf,"");
	       if(strncmp(idd,"FACIT",5)==0)
	       {
		       facfile("itstud.txt",buf);
	       }
	       else if(strncmp(idd,"FACEC",5)==0)
		       facfile("ecestud.txt",buf); 
	       else if(strncmp(idd,"18bit",5)==0)
		       stufile(idd,"itstud.txt",buf);
	       else if(strncmp(idd,"18bec",5)==0)                                                                                                                         stufile(idd,"ecestud.txt",buf);
	       send(newsockfd,buf,sizeof(buf),0); 
	       strcpy(buf,"");
      }
       else
       {
	       strcpy(buf,"fail");
	       send(newsockfd,buf,sizeof(buf),0);
	       exit(0);
       }
     }	
       close(sockfd);
       return 0;
       }
