#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
main(){
      struct servent* se = getservbyname("telnet", "tcp");
        
      printf("%d\n", ntohs(se->s_port));
}
