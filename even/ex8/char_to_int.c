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
	int n ;
	scanf("%d",&n);
	char c=n+65;
	printf("%c",c);
	
}
