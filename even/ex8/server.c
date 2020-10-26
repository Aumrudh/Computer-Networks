#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

int minimum(int a[],int m[],int k)
{
	int min=999;
	int i,t;
	for(i=1;i<=k;i++)
	{
		if(m[i]!=1)
		{
			if(min>a[i])
			{
				min=a[i];
				t=i;
			}
		}
	}
	return t;
}

int findprev(int a,int m[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
			if(m[i+1]==a)
			return m[i];
	}
}

void djikstra(int mat[4][4],int n,int src)
{
        int i,j,u,mark[20],hop[20],min[20],me[20];
        int cnt,k=0,p;
        for(j=1;j<=n;j++)
        {
                mark[j]=0;
                me[j]=999;
                hop[j]=-1;
        }
        me[src]=0;
        hop[src]=0;
        printf("\nRouting table for %d",src);
        cnt=1;
        while(cnt<n)
        {
                u=minimum(me,mark,n);
                min[k++]=u;
                mark[u]=1;
                cnt++;
                for(i=1;i<=n;i++)
                {
                                if(mat[u][i]>0)
                                {
                                        if(me[i]>me[u]+mat[u][i])
                                        {
                                                me[i]=me[u]+mat[u][i];
                                                if(mat[src][u]!=0 && mat[src][u]!=-1)
                                                        hop[i]=u;
                                                else if(src==u)
                                                        hop[i]=i;
                                                else
                                                {
                                                        while(hop[i]==-1)
                                                        {
                                                                p=findprev(u,min,k);
                                                                if(mat[src][p]!=0 && mat[src][p]!=-1)
                                                                                hop[i]=p;
                                                        }
                                                }
                                        }
                                }
                }
        }
        printf("\nDEST\tNEXTHOP\tMETRIC\n");
        for(i=1;i<=n;i++)
                printf("%d\t%d\t%d\n",i,hop[i],me[i]);
}

int main(){
        int sd,b,l,ad,len;
        char msg[100];
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("Enter the port no : ");
        int portno;
        scanf("%d",&portno);
        server.sin_port=htons(portno);
        server.sin_addr.s_addr=htonl(INADDR_ANY);

        //socket creation
	int mat[4][4]={{0, 2, 3, 99},{ 2, 0, 99 ,1},{ 3, 99 ,0 ,4},{ 99, 1 ,4, 0}};
        /*for(int i=1;i<=4;i++)
	{
		printf("\n");
		for(int j=1;j<=4;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}*/
	int i,j,n;
	/*printf("Enter no.of router : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}

	}*/
        sd=socket(AF_INET,SOCK_STREAM,0);
        if(sd==-1){
                printf("Socker=t creation failed\n");
                exit(0);
        }
        else{
                printf("Socket Created\n");
        }

        //binding

        b=bind(sd,(struct sockaddr *)&server,sizeof(server));

        if(b==-1){
                printf("Binding failed\n");
                exit(0);
        }
        else{
                printf("Binded\n");
        }

        //listen

        l=listen(sd,5);
        if(l==-1){
                printf("Listen failed\n");
                exit(0);
        }
        else{
                printf("Listening\n");
        }

        //accept

        len=sizeof(client);
        ad=accept(sd,(struct sockaddr*)&client,&len);
        if(ad==-1){
                printf("Accept failed\n");
                exit(0);
        }
        else{
                printf("Accepted\n");
        }
        printf("Connection established\n");
        recv(ad,msg,100,0);
	int src=atoi(msg);
        printf("Client side : %s\n",msg);
	//djikstra(mat,4,1);
	n=4;
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}		
	int u,mark[20],hop[20],min[20],me[20];
        int cnt,k=0,p;
        printf("\nEnter source vertex..");
        scanf("%d",&src);
        for(j=1;j<=n;j++)
        {
                mark[j]=0;
                me[j]=999;
                hop[j]=-1;
        }
        me[src]=0;
        hop[src]=0;
        printf("Routing table for : %d\n",src);
        cnt=1;
        while(cnt<n)
        {
                u=minimum(me,mark,n);
                min[k++]=u;
                mark[u]=1;
                cnt++;
                for(i=1;i<=n;i++)
                {
                                if(mat[u][i]>0)
                                {
                                        if(me[i]>me[u]+mat[u][i])
                                        {
                                                me[i]=me[u]+mat[u][i];
                                                if(mat[src][u]!=0 && mat[src][u]!=-1)
                                                        hop[i]=u;
                                                else if(src==u)
                                                        hop[i]=i;
                                                else
                                                {
                                                        while(hop[i]==-1)
                                                        {
                                                                p=findprev(u,min,k);
                                                                if(mat[src][p]!=0 && mat[src][p]!=-1)
                                                                                hop[i]=p;
                                                        }
                                                }
                                        }
                                }
                }
        }	
	
	for(i=1;i<=n;i++)
		printf("%d\t%d\t%d\n",i,hop[i],me[i]);
	/*sprintf(msg,"%d",n);
	send(ad,msg,100,0);
	send(ad,hop,20,0);
	send(ad,me,20,0);*/
}
