#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define MAX_VERTEX_NUM 20

typedef int Status;
typedef char ElemType;

typedef struct{
	int vexnum,arcnum;
	ElemType vexs[MAX_VERTEX_NUM];
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MGraph;

FILE *fp;

int LocateVex(MGraph G,ElemType v)
{
	int k;
	for(k=0;k<G.vexnum;k++)
    {
		if(G.vexs[k]==v) return k;
	}
	return -1;
}

int FirstAdjVex(MGraph G,int i)
{
	if(i<0||i>G.vexnum)return -2;
	for(int k=0;k<G.vexnum;k++)
		if(G.arcs[i][k]==1)return k;
	return -1;
}

int NextAdjVex(MGraph G,int i,int j){
	if((i<1)||i>G.vexnum)return -1;
	if((j<1)||j>G.vexnum)return -1;
	int k;
	for(k=j+1;k<G.vexnum;k++)
	{
		if(G.arcs[i][k]==1)return k;
	}
	return -1;
}

void PutDu(MGraph G){
	int i,j;
	int s=0;
	printf("\n������ڵ�Ķ�����\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			if(G.arcs[i][j]==1)
				s++;
			printf("�ڵ�%c�Ķ���Ϊ��%d\n",G.vexs[i],s);
			s=0;
	}
}



void CreateMGraph(MGraph &G){
	int i,j,k,m,n;
	ElemType v,w;
	fscanf(fp,"%d,%d",&G.vexnum,&G.arcnum);
	printf("%d,%d\n",G.vexnum,G.arcnum);
	for(k=0;k<G.vexnum;k++)
	{
            fscanf(fp,"%c",&G.vexs[k]);
            printf("%c\n",G.vexs[k]);
	}
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=0;
	}
	for(k=0;k<G.arcnum;k++)
	{
		fscanf(fp,"\r\n%c,%c",&v,&w);
		printf("%c,%c\n",v,w);
		n=LocateVex(G,v);
		m=LocateVex(G,w);
		G.arcs[m][n]=1;
		G.arcs[n][m]=1;
	}
}

void printf_MGraph(MGraph G){
printf("����ͼGΪ��\n");
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			printf("%3d",G.arcs[i][j]);
		printf("\n");
	}
}

int visited[MAX_VERTEX_NUM];

void DFS(MGraph G,int v)
{
	printf("%2c",G.vexs[v]);
	visited[v]=1;
	int w=FirstAdjVex(G,v);
	while(w!=-1)
	{
		if(visited[w]==0)DFS(G,w);
		w=NextAdjVex(G,v,w);
	}
}

void DFSTraverse(MGraph G){
	int v;
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(v=0;v<G.vexnum;v++)
		if(visited[v]==0)
			DFS(G,v);
		printf("\n");

}

int main()
{
	MGraph G;
	int i,k;
	if((fp=fopen("a1.txt","r"))==NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		exit(1);
	}
else printf("���ļ��ɹ���");
	CreateMGraph(G);
	printf("\n��������Ҫ�鿴�ĵ�һ���ڽӵ�Ķ����λ�ã�");
	scanf("%d",&i);
	k=FirstAdjVex(G,i);
	printf("����һ���ڽӵ��λ���ǣ�%d",k);
	printf("\n");
	printf("���ڽӾ������ʽ���ͼ��\n");
	printf_MGraph(G);
	printf("\nͼ����ȱ����ǣ�");
	DFSTraverse(G);
	PutDu(G);
	fclose(fp);
	getchar();
	return 0;
}
