// C program to demonstrate 
// example of time() function. 
#include <stdio.h> 
#include <time.h> 
#include <unistd.h>
int main () 
{ 
	time_t begin , end ; 
	
	begin = time(NULL); 
        sleep(5);
        end = time(NULL);
	printf("Seconds %f \n",difftime(end,begin)); 
        if( difftime(end,begin) == 5 ) {
	    printf("Time Diff is 5 Seconds");
	}	
	return(0); 
} 

