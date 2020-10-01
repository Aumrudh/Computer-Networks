#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main()
{
        int sid,sid1,len,r,c,s,cid;
        char * buf;
        struct sockaddr_in cli,ser;
        buf=(char *)malloc(10*sizeof(char));
        sid=socket(AF_INET,SOCK_DGRAM,0);
        if(sid==-1)
        {
                perror("socket");
        }
        ser.sin_family=AF_INET;
        ser.sin_port=htons(2029);
        inet_aton("127.0.0.1",&ser.sin_addr);
        printf("Enter msg:\n");
        scanf("%s",buf);
        r=sendto(sid,buf,sizeof(buf),0,(struct sockaddr *)&ser,sizeof(ser));
        if(r==-1)
        {
                perror("Sentto");
        }
        cid=fork();
        {
                s=sizeof(ser);
                if(cid!=0)
                {
                 while(strcmp(buf,"over"))
                 { 
                 r=recvfrom(sid,buf,sizeof(buf),0,(struct sockaddr *)&ser,&s);
                 if(r==-1)
                 {
                    perror("Recvfrom");
                 }
                  printf("Server data:\n");
                  printf("%s\n",buf);
                  }
                }
                else
                {
                   while(strcmp(buf,"over"))
                   {
                    printf("Enter msg:\n");
                    scanf("%s",buf);
                    {
                    r=sendto
                (sid,buf,sizeof(buf),0,(struct sockaddr *)&ser,sizeof(ser));
                        if(r==-1)
                        {
                                perror("Sendto");
                        }
                        }
                   }
                }
                r=shutdown(sid,2);
                if(r==-1)
                {
                        perror("Shutdown");
                }
                r=close(sid);
                if(r==-1)
                {
                        perror("Close");
                }
          }			
}
