#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
        char src;
        char dst;
        int length;
}node;
node obj[4],temp[10],perm[4];

void validate(int c){
	if(c>3){
		printf("Enter Valid Input");
		exit(1);
	}
}
/*int comparator (const void * a, const void * b) {
	   return ( *(int*)a - *(int*)b );
}*/

void bsort(node temp[],int max){
	struct node t;
	for(int i=0;i<max-1;i++){
        	for(int j=i+1;j<max;j++){
                	if(temp[i].length>temp[j].length){
                        	t=temp[j];
                        	temp[j]=temp[i];
                        	temp[i]=t;
                	}
         	}
	}
}


void clean(node temp[],int max){
	for(int i=1;i<max+1;i++) 
		temp[i-1]=temp[i];

}

int main(){
int matrix[4][4];
printf("Enter the distance between each rows and columns : \n");
for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
        	scanf("%d",&matrix[i][j]);
        }
}
int c;
printf("Enter 1-a ,2-b,3-c,4-d : ");
scanf("%d", &c);c =c -1;
validate(c);
for(int i=0,j=0;i<4;j++,i++) {
      obj[i].src=c+65;
      obj[i].dst=j+65;
      obj[i].length=matrix[c][j];
}
//perm[0]=obj[0];
int max;
for(int i=0;i<4;i++){
	temp[i]=obj[i];
	max=i;
   
}

for(int i=0;i<4;i++){
	printf("%c  %c  %d \n",obj[i].src,obj[i].dst,obj[i].length);
}

/*struct node t;

for(int i=0;i<max-1;i++){
	for(int j=i+1;j<max;j++){
        	if(temp[i].length>temp[j].length){
                	t=temp[j];
                        temp[j]=temp[i];
                        temp[i]=t;
                }
         }
}

//qsort(temp, 4, sizeof(node), comparator); 
*/
bsort(temp,max);
printf("After sort\n");
for(int i=0;i<max;i++){
	        printf("%c  %c  %d \n",temp[i].src,temp[i].dst,temp[i].length);
}


perm[0]=temp[0];

clean(temp,max);
printf("Clean \n");
for(int i=0;i<max;i++){
	                printf("%c  %c  %d \n",temp[i].src,temp[i].dst,temp[i].length);
}
max-=1;

perm[1]=temp[0];
clean(temp,max);
printf("clen 2\n");
for(int i=0;i<max;i++){
	printf("%c  %c  %d \n",temp[i].src,temp[i].dst,temp[i].length);
}
max-=1;
}
