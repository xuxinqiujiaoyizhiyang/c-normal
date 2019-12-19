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
 printf("\n\n\t\t********************建立图的种类***********************\n");
 printf("\t\t**   1.建立有向图(按0)                                   **\n");
 printf("\t\t**   2.建立有向网(按1)                                   **\n");
 printf("\t\t**   3.建立无向图(按2)                                   **\n");
 printf("\t\t**   4.建立无向网(按3)                                   **\n");
 printf("\t\t*******************************************************\n");
 printf("\t\t     您的输入：");
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
int CreateUDN(MGraph &G)//无向网
{
    int w,m,n;
    vertex v1,v2;
    printf("请输入顶点个数和弧数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.arcnum;++i)
    {
        printf("请输入第%d个顶点的名称：",i+1);
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
            printf("请输入要建立的关系涉及到的第一个顶点：");
            scanf("%s",&v1);
             printf("请输入要建立的关系涉及到的第二个顶点：");
            scanf("%s",&v2);
            printf("请输入两个顶点之间的权值：");
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
int CreateUDG(MGraph &G)//无向图
{
     int w,m,n;
    vertex v1,v2;
    printf("请输入顶点个数和弧数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.vexnum;++i)
    {
        printf("请输入第%d个顶点的名称：",i+1);
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
            printf("请输入要建立的关系涉及到的第一个顶点：");
            scanf("%s",&v1);
             printf("请输入要建立的关系涉及到的第二个顶点：");
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
int CreateDG(MGraph &G)//有向图
{
    int w,m,n;
    vertex v1,v2;
    printf("请输入顶点个数和弧数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.arcnum;++i)
    {
        printf("请输入第%d个顶点的名称：",i+1);
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
             printf("请输入要建立的关系涉及到的第一个顶点：");
            scanf("%s",&v1);
             printf("请输入要建立的关系涉及到的第二个顶点：");
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
int CreateDN(MGraph &G)//有向网
{
    int w,m,n;
    vertex v1,v2;
    printf("请输入顶点个数和弧数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.arcnum;++i)
    {
        printf("请输入第%d个顶点的名称：",i+1);
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
            printf("请输入要建立的关系涉及到的第一个顶点：");
            scanf("%s",&v1);
             printf("请输入要建立的关系涉及到的第二个顶点：");
            scanf("%s",&v2);
             printf("请输入两个顶点之间的权值：");
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
	G.visited[i]=TRUE;   //被访问的标记
	printf("%s->",G.vexs[i]);
	for(j=0;j<G.vexnum;j++)
	{
		if(G.arcs[i][j].adj==1&&!G.visited[j])   //边(i,j)存在且j顶点未被访问，递归
			DFS(G,j);
	}
}
//深度优先遍历
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
	for(i=0;i<G.vexnum;i++)//对每一个顶点做循环
	{
		if(!G.visited[i])			//若是未被访问过就处理
		{
			G.visited[i] = TRUE;	//设置当前顶点访问过
			printf("%s ",G.vexs[i]);//打印顶点
			Enqueue(Q,i);		//将此顶点入队列
			while(Q.front!=Q.rear)//若当前顶点不为空
			{
				Dequeue(Q,i);	 //将队中元素出队列，赋值给i
				for(j=0;j<G.vexnum;j++)
				{
					//判断其他顶点若与当前顶点存在边且未被访问过
					if(G.arcs[i][j].adj ==1 && !G.visited[j])
					{
						G.visited[j] = TRUE;//将找到的此顶点标记为已访问
						printf("->%s ",G.vexs[j]);//打印此顶点
						Enqueue(Q,j);//将找到的此顶点入队列
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
	printf("\n图遍历完毕");
}
