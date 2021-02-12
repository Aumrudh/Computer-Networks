#include<sys/socket.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
int sockfd,newsockfd,portnumber,packsize,windowsize,ascii;
char str[20],temp[20];
struct sockaddr_in seraddr,cli_addr;
int clength=sizeof(cli_addr);
printf("Enter the port number :");
scanf("%d",&portnumber);
seraddr.sin_family=AF_INET;
seraddr.sin_port=htons(portnumber);
seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
sockfd=socket(AF_INET,SOCK_STREAM,0);
bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
listen(sockfd,1);
newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clength);
read(newsockfd,str,sizeof(str));
printf("Packet size: %s\n",str);
packsize=atoi(str);
char packet[packsize];
read(newsockfd,str,sizeof(str));
windowsize=atoi(str);
printf("Window size: %s\n",str);
register int i=0;
register int j=0;
int check,count,num,error;
char *ptr;
char reply[20];
strcpy(reply,"1");
int AcqNo=0;
int flag=2;
int ch;
while(1)
{
        read(newsockfd,str,sizeof(str));
        ptr=strtok(str," ");
        while(1)
        {

                //ptr=strtok(NULL," ");
                //printf("%s\t",ptr);
                if (AcqNo==atoi(ptr))
                {

                ptr=strtok(NULL," ");
                check=atoi(ptr);
                num=check;
                count=0;
                while(num)
                {
                count+=num&1;
                num>>=1;
                }
                if (count&1)
                {
                printf("Acknowledgement not given for %c\n",check>>1);
                strcpy(reply,"0");
                flag=1;
                }
                else
                {
                check=atoi(ptr);
                printf("Give Acknowledgement for %c     :",check>>1);
                packet[j]=check>>1;
                j+=1;
                scanf("%d",&ch);
                printf("\n");
                //printf("%c\n",check>>1);
                AcqNo+=1;
                }

                }
                else
                {
                        if (flag==1)
                        {
                        flag=2;
                        printf("Discarded Expecting seqNo %d\n",AcqNo);
                        }
                        else
                        {
                        flag-=1;
                        }

                }
                ptr=strtok(NULL," ");
                if (ptr==NULL)
                {
                        break;
                }
        }
        write(newsockfd,reply,sizeof(reply));
        fflush(stdout);
        if (strcmp(reply,"1")==0)
        {
        i+=windowsize;
        }
        strcpy(reply,"1");
        if (AcqNo==packsize)
        {
                break;
        }

}
packet[j]='\0';
printf("%s",packet);
close(newsockfd);
close(sockfd);
return 0;
}
