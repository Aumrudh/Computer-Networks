#include<stdio.h>
int main(){

int n =4;
 int mat[4][4]={{0,2,3,99},
	  {2,0,99,1},
	  {3,99,0,4},
	  {99,1,4,0}
 };
for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
	}
