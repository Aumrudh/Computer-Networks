#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

#define WAIT 3

int main ()
{
    char            name[20] = {0}; // in case of single character input
    fd_set          input_set;
    struct timeval  timeout;
    int             ready_for_reading = 0;
   
    timeout.tv_sec = WAIT;
    timeout.tv_usec = 0; 
    printf("Enter name : \n");
    FD_SET(0, &input_set);
    ready_for_reading = select(1, &input_set, NULL, NULL, &timeout);

     if (ready_for_reading == -1) {
 
        printf("Timeout \n");
        return -1;
     }
 

      if (ready_for_reading) {
        scanf("%s" , name);
/*	int read_bytes = read(0, name, 19);
	 if(name[read_bytes-1]=='\n'){
		         --read_bytes;
			         name[read_bytes]='\0';
	 if(read_bytes!=0){	*/	         
	     printf("Value : %s \n",name);
	// }
     // }
      }
      else {
	              printf(" %d Seconds are over - no data input \n", WAIT);
		          }

       //printf("Value : %s \n",name);
}



