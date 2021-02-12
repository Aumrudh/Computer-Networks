#include<stdio.h>
#include<string.h>
struct lsp
{
	int no;
	int neighbour[10];
	int cost[10];
};
typedef struct lsp lsp;
//int minimum(int [],int [],int);
//int findprev(int,int[],int);
//void djikstra(int [][20],int);

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

void djikstra(int mat[][20],int n)
{
	int i,j,u,mark[20],hop[20],min[20],me[20];
	int src,cnt,k=0,p;
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
main()
{
	int	mat[20][20];
	
	lsp l[20];
	int n,k,num,i,j,p;
	printf("\nEnter no.of router...");
	scanf("%d",&n);
	/*for(i=1;i<=n;i++)
	{
		printf("\nenter no.of neighbour for node[%d]",i);
		scanf("%d",&l[i].no);
		printf("\nlsp of node:%d",i);
		for(j=1;j<=l[i].no;j++)
		{
			printf("\nEnter ur neighbour..");
			scanf("%d",&l[i].neighbour[j]);
			printf("\nEnter cost..");
			scanf("%d",&l[i].cost[j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				mat[i][j]=0;
			else
				mat[i][j]=-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		num=l[i].no;
		for(k=1;k<=num;k++)
		{
			p=l[i].neighbour[k];
			mat[i][p]=l[i].cost[k];
		}
	}*/
	printf("\nAdjacency matrix..\n");
	for(i=1;i<=n;i++)
	{
		//printf("\n");
		for(j=1;j<=n;j++)
			scanf("%d",&mat[i][j]);
			//printf("%d\t",mat[i][j]);
		//printf("\n");
	}
	djikstra(mat,n);
}
