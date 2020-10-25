#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
        char src;
        char dst;
        int length;
}obj[10],temp[10],perm[4];
void validate(int c){
	if(c>3){
		printf("Enter Valid Input");
		exit(1);
	}
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
perm[0]=obj[0];
for(int i=1;i<10;i++){
	temp[i]=obj[i];

}

for(int i=0;i<4;i++){
	printf("%c  %c  %d \n",temp[i].src,obj[i].dst,obj[i].length);
}

}
