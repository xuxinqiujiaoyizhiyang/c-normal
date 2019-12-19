 #include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
    }LNode,*LinkList;
void CreateList_L(LinkList &L)
    {  //先建立一个头结点
        L = (LinkList) malloc (sizeof (LNode));
        if(L==NULL)
        {
            printf("error");
            exit(1);
        }
        L->next = NULL;//创建空链表
        }
void GetList_L(LinkList &L,int n)
       {
           LinkList p,q;
        q=L;
        int i;
        for (i = 0; i <n; i++)
        {p = (LinkList) malloc (sizeof (LNode));
        scanf("%d",&p->data);
         p->next = q->next;
         q->next=p;
        q=p;
        }

    }
int Getlem_L(LinkList &L,int i,int &e)
{
    int j=1;
    LinkList p;
    p=L->next;
    while(p&&j<i)
        {
            p=p->next;
            ++j;
        }
        if(!p||j>i) return 1;
        e=p->data;
        return 0;
}
int ListInsert_L(LinkList &L,int i,int e)
{   LinkList p,q;
    int j=0;
    p=L;
    while (p&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
        return 1;
    else
    {   q = (LinkList) malloc (sizeof (LNode));
        q->next=p->next;
        q->data=e;
        p->next=q;
    }
    return 0;
}
int Listdelete_L(LinkList &L,int i)
{   int j=0;
    LinkList q,p;
    p=L;
    while(p->next&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1)
        return 1;
        q=p->next;
        p->next=q->next;
        free(q);
    return 0;
}
void Listprint_L(LinkList L)
{   LinkList p;
    p=L->next;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
main()
{   int a,b,c,e;
    LinkList p,q,y,d;
    int i,k,l,x;
    CreateList_L(p);
    printf("请输入数组：");
    GetList_L(p,10);
    printf("请输入要查找的位置：");
    scanf("%d",&e);
    Getlem_L(p,e,k);
    printf("%d\n",k);
    printf("请输入要加入数据的位置：");
    scanf("%d",&a);
    printf("请输入要加入数据的大小：");
    scanf("%d",&b);
    ListInsert_L(p,a,b);
    printf("数组整体为：");
    Listprint_L(p);
    printf("\n");
    printf("请输入要删除数据的位置：");
    scanf("%d",&c);
    Listdelete_L(p,c);
    Listprint_L(p);
}
