#include<stdio.h>
#include<stdlib.h>
typedef struct bitnode
{
char data;
struct bitnode *lchild,*rchild;
}bitnode,*bitree;
bitree create_tree()//���򴴽�
{
char a;
bitree root;
scanf("%c",&a);
fflush(stdin);
if(a=='#')
    return NULL;
else
{
root=(bitnode*)malloc(sizeof(bitnode));
root->data=a;
root->lchild=create_tree();
root->rchild=create_tree();
}
return root;
}

void inorder(bitree root)//�и�����
{
bitree s[100];
int top=0;
while(root||top)
{
while(root)
{
s[++top]=root;
root=root->lchild;
}
if(top)
{
putchar(s[top]->data);
root=s[top--]->rchild;
}
}
}
main()
{
bitree root=NULL;
root=create_tree();//��������Ϊ����������У��������
inorder(root);
printf("\n");
}
