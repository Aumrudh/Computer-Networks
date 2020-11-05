#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<utmp.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
main(){
  struct hostent *he;
  struct in_addr addr;
   char temp[100]="8.8.8.8";
  //inet_aton(temp, &addr);
    addr.s_addr = inet_addr(temp);
   he = gethostbyaddr((char *)&addr, sizeof(addr), AF_INET);
  //he = gethostbyaddr("8.8.8.8",4,AF_INET);
printf("Host name: %s\n", he->h_name);
}
