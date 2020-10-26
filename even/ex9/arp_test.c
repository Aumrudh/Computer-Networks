#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/* main() returns int, not void. */
int main( void ) {

	  char result[1000];
//	    strcpy(result,system("arp.exe -a"));
	    system("arp.exe -a > arp_generation.txt");
//printf("%s",result);
	        return 0;
}
