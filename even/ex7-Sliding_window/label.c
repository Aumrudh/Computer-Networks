#include<stdio.h>
main(){
	int a;
label:	printf("enter : ");
	scanf("%d",&a);
	if(a==0){
		goto label;
	}
	else{
		printf("%d",a);
	}
}
