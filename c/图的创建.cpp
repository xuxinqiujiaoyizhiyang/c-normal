#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<limits.h>
#define Infinity INT_MAX
#define max_vertex_num 20
#define OK 1
#define ERROR 1
#define TRUE 1
#define FALSE 0
typedef char vertex[100];
typedef enum{DG,DN,UDG,UDN} Graphkind;
typedef struct ArcCell
{
int adj;
char *info;
}ArcCell,AdjMatrix[max_vertex_num][max_vertex_num];
typedef struct{
    vertex vexs[max_vertex_num];
    AdjMatrix arcs;
    int vexnum,arcnum;
    Graphkind kind;
    int *visited;
}MGraph;
typedef struct _queue {
    int data[max_vertex_num];
    int front;
    int rear;
} queue;
void menu()
{
 int n;
 printf("\n\n\t\t********************����ͼ������***********************\n");
 printf("\t\t**   1.��������ͼ(��0)                                   **\n");
 printf("\t\t**   2.����������(��1)                                   **\n");
 printf("\t\t**   3.��������ͼ(��2)                                   **\n");
 printf("\t\t**   4.����������(��3)                                   **\n");
 printf("\t\t*******************************************************\n");
 printf("\t\t     �������룺");
    fflush(stdin);
}
void Initqueue(queue &Q)
{
    //Q=(queue *)malloc(100*sizeof(queue));
    Q.front=0;
    Q.rear=0;
}
int Enqueue(queue &Q,int i)
{
    if((Q.rear+1)%max_vertex_num==Q.front)
        return 1;
        Q.data[Q.rear]=i;
    Q.rear=(Q.rear+1)%max_vertex_num;
    return 0;
}
int Dequeue(queue &Q,int &i)
{
    if(Q.front==Q.rear)
        return 1;
        i=Q.data[Q.front];
    Q.front=(Q.front+1)%max_vertex_num;
    return 0;
}
int LocateVex(MGraph G,vertex u)
 { int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vexs[i])==0)
       return i;
   return -1;
 }
int Creategraph(MGraph &G)
{
    int CreateUDN(MGraph &G);
    int CreateDN(MGraph &G);
    int CreateDG(MGraph &G);
    int CreateUDG(MGraph &G);
    scanf("%d",&G.kind);
    switch(G.kind)
    {
        case 0:return CreateDG(G);
        case 1:return CreateDN(G);
        case 2:return CreateUDG(G);
        case 3:return CreateUDN(G);
        default:return ERROR;
        }
}
int CreateUDN(MGraph &G)//������
{
    int w,m,n;
    vertex v1,v2;
    printf("�����붥������ͻ�����");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.arcnum;++i)
    {
        printf("�������%d����������ƣ�",i+1);
        scanf("%s",&G.vexs[i]);
    }
    for(int i=0;i<G.vexnum;++i)
        for(int j=0;j<G.vexnum;j++)
    {
        G.arcs[i][j].info=(char *)malloc(10*sizeof(char));
        G.arcs[i][j].adj=INT_MAX;
        G.arcs[i][j].info=NULL;
        }
    for(int k=0;k<G.arcnum;++k)
        {
            printf("������Ҫ�����Ĺ�ϵ�漰���ĵ�һ�����㣺");
            scanf("%s",&v1);
             printf("������Ҫ�����Ĺ�ϵ�漰���ĵڶ������㣺");
            scanf("%s",&v2);
            printf("��������������֮���Ȩֵ��");
            scanf("%d",&w);
            m=LocateVex(G,v1);
            n=LocateVex(G,v2);
            G.arcs[m][n].adj=w;
            G.arcs[n][m].adj=G.arcs[m][n].adj;
        }
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.vexnum;j++)
    {
        printf("%d",G.arcs[i][j].adj);
        printf("\t");
       }
       printf("\n");
    }
    return OK;
}
int CreateUDG(MGraph &G)//����ͼ
{
     int w,m,n;
    vertex v1,v2;
    printf("�����붥������ͻ�����");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.vexnum;++i)
    {
        printf("�������%d����������ƣ�",i+1);
        scanf("%s",&G.vexs[i]);
    }
    for(int i=0;i<G.vexnum;++i)
        for(int j=0;j<G.vexnum;j++)
    {
        G.arcs[i][j].info=(char *)malloc(10*sizeof(char));
        G.arcs[i][j].adj=0;
        G.arcs[i][j].info=NULL;
        }
    for(int k=0;k<G.arcnum;++k)
        {
            printf("������Ҫ�����Ĺ�ϵ�漰���ĵ�һ�����㣺");
            scanf("%s",&v1);
             printf("������Ҫ�����Ĺ�ϵ�漰���ĵڶ������㣺");
            scanf("%s",&v2);
            m=LocateVex(G,v1);
            n=LocateVex(G,v2);
            G.arcs[m][n].adj=1;
            G.arcs[n][m].adj=G.arcs[m][n].adj;
        }
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.vexnum;j++)
    {
        printf("%d",G.arcs[i][j].adj);
        printf("\t");
       }
       printf("\n");
    }
    return OK;
}
int CreateDG(MGraph &G)//����ͼ
{
    int w,m,n;
    vertex v1,v2;
    printf("�����붥������ͻ�����");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.arcnum;++i)
    {
        printf("�������%d����������ƣ�",i+1);
        scanf("%s",&G.vexs[i]);
    }
    for(int i=0;i<G.vexnum;++i)
        for(int j=0;j<G.arcnum;j++)
    {
        G.arcs[i][j].info=(char *)malloc(10*sizeof(char));
        G.arcs[i][j].adj=0;
        G.arcs[i][j].info=NULL;
        }
    for(int k=0;k<G.arcnum;++k)
        {
             printf("������Ҫ�����Ĺ�ϵ�漰���ĵ�һ�����㣺");
            scanf("%s",&v1);
             printf("������Ҫ�����Ĺ�ϵ�漰���ĵڶ������㣺");
            scanf("%s",&v2);
            m=LocateVex(G,v1);
            n=LocateVex(G,v2);
            G.arcs[m][n].adj=1;
        }
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.vexnum;j++)
    {
        printf("%d\t",G.arcs[i][j].adj);
       }
       printf("\n");
    }
    return OK;
}
int CreateDN(MGraph &G)//������
{
    int w,m,n;
    vertex v1,v2;
    printf("�����붥������ͻ�����");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.arcnum;++i)
    {
        printf("�������%d����������ƣ�",i+1);
        scanf("%s",&G.vexs[i]);
    }
    for(int i=0;i<G.vexnum;++i)
        for(int j=0;j<G.arcnum;j++)
    {
        G.arcs[i][j].info=(char *)malloc(10*sizeof(char));
        G.arcs[i][j].adj=INT_MAX;
        G.arcs[i][j].info=NULL;
        }
    for(int k=0;k<G.arcnum;++k)
        {
            printf("������Ҫ�����Ĺ�ϵ�漰���ĵ�һ�����㣺");
            scanf("%s",&v1);
             printf("������Ҫ�����Ĺ�ϵ�漰���ĵڶ������㣺");
            scanf("%s",&v2);
             printf("��������������֮���Ȩֵ��");
            scanf("%d",&w);
            m=LocateVex(G,v1);
            n=LocateVex(G,v2);
            G.arcs[m][n].adj=w;
        }
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.arcnum;j++)
    {
        printf("%d\t",G.arcs[i][j].adj);
       }
       printf("\n");
    }
    return OK;
}
void DFS(MGraph G,int i)
{
	int j;
	G.visited[i]=TRUE;   //�����ʵı��
	printf("%s->",G.vexs[i]);
	for(j=0;j<G.vexnum;j++)
	{
		if(G.arcs[i][j].adj==1&&!G.visited[j])   //��(i,j)������j����δ�����ʣ��ݹ�
			DFS(G,j);
	}
}
//������ȱ���
void DFStraverse(MGraph G)
{

	int i;
	G.visited=(int *)malloc(100*sizeof(int));
	for(i=0;i<G.vexnum;i++)
		G.visited[i]=FALSE;
	for(i=0;i<G.vexnum;i++)
			if(!G.visited[i])
				DFS(G,i);

}
void bfs(MGraph G)
{
    int i,j;
	queue Q;
	 G.visited=(int *)malloc(100*sizeof(int));
	for(i=0;i<G.vexnum;i++)
	{
		G.visited[i] = FALSE;
	}
	Initqueue(Q);
	for(i=0;i<G.vexnum;i++)//��ÿһ��������ѭ��
	{
		if(!G.visited[i])			//����δ�����ʹ��ʹ���
		{
			G.visited[i] = TRUE;	//���õ�ǰ������ʹ�
			printf("%s ",G.vexs[i]);//��ӡ����
			Enqueue(Q,i);		//���˶��������
			while(Q.front!=Q.rear)//����ǰ���㲻Ϊ��
			{
				Dequeue(Q,i);	 //������Ԫ�س����У���ֵ��i
				for(j=0;j<G.vexnum;j++)
				{
					//�ж������������뵱ǰ������ڱ���δ�����ʹ�
					if(G.arcs[i][j].adj ==1 && !G.visited[j])
					{
						G.visited[j] = TRUE;//���ҵ��Ĵ˶�����Ϊ�ѷ���
						printf("->%s ",G.vexs[j]);//��ӡ�˶���
						Enqueue(Q,j);//���ҵ��Ĵ˶��������
					}
				}
			}
		}
	}
}
int main()
{
	menu();
    MGraph G;
    Creategraph(G);
	printf("\n");
	DFStraverse(G);
	printf("\n");
	bfs(G);
	printf("\nͼ�������");
}
