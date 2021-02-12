#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include <time.h>
int main(void)
{
time_t begin,end;
int a,clisock,portnumber,packsize,windowsize,ascii,choice,count=0,newsockfd;
char str[20],msg[20];
struct sockaddr_in cli_addr;

printf("Enter thr port number :");
scanf("%d",&portnumber);

cli_addr.sin_port=htons(portnumber);
cli_addr.sin_family=AF_INET;
cli_addr.sin_addr.s_addr=INADDR_ANY;
clisock=socket(AF_INET,SOCK_STREAM,0);

newsockfd=connect(clisock,(struct sockaddr*)&cli_addr,sizeof(cli_addr));

printf("\nEnter the Packet size:");
scanf("%d",&packsize);
char packets[packsize];
sprintf(str,"%d",packsize);
write(clisock,str,sizeof(str));

printf("\nEnter the window size:");
scanf("%d",&windowsize);
sprintf(str,"%d",windowsize);
write(clisock,str,sizeof(str));

printf("\nEnter the message   :");
scanf("%s",msg);
register int i=0;
register int j=0;
register int k=0;
char temp[20];
strcpy(temp,"");
char send[2];
int num;
int seqno=0;
char seqNo[20];
int rply;
char reply[20];
while(i<packsize)
{
        k=i;
        while(j<windowsize)
        {
                ascii=msg[k+j];
                printf("For value %c 1.Insert error 2.Continue  :",ascii);
                scanf("%d",&choice);
                printf("\n");
                num=ascii;
                count=0;
                while(num)
                {
                count+=num&1;
                num>>=1;
                }
                if (count&1)//count is odd
                {
                if(choice==1)
                {
                   ascii=ascii<<1;//allocate space
                }
                else
                {
                    ascii=ascii<<1;
                    ascii=((1 << 0) | ascii);//set the least significant bit
                }
                }
                else //count is even
                {
                if (choice==1)
                {
                            ascii=ascii<<1;
                            ascii=((1 << 0) | ascii);//set the least significant bit
                }
                else
                {
                            ascii=ascii<<1;//allocate space
                }
                }
               // ascii=ascii>>1;
                sprintf(seqNo,"%d",seqno);
                strcat(seqNo," ");
                strcat(temp,seqNo);
                sprintf(send,"%d",ascii);
                //printf("%d",ascii);
                strcat(temp,send);
                seqno+=1;
                strcat(temp," ");
                j+=1;
        }
        write(clisock,temp,sizeof(temp));
        //read(clisock,reply,sizeof(reply));
        begin=time(NULL);
        read(clisock,reply,sizeof(reply));
        end=time(NULL);
        int diff=0;
        diff=difftime(end,begin);
        rply=atoi(reply);

        if (rply==1 && diff<10)
        {
                //printf("Checked\n");
                i+=windowsize;
        }
        else if (diff>10)
        {
                printf("TIME OUT\n");
                seqno-=windowsize;
        }
        else
        {
                seqno-=windowsize;
        }

        j=0;
       // printf("%s\n",temp);
       //write(clisock,temp,sizeof(temp));
        strcpy(temp,"");
        //i+=windowsize;
}
close(clisock);
return 0;
}