#include<stdlib.h>
#include <stdio.h>
#include <string.h>
//ABC##DE#GF###
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree CreateBiTree(BiTree T){
	char ch;
	scanf("%c",&ch);
	if(ch=='#') T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
			exit(1);
		T->data=ch;
		T->lchild=CreateBiTree(T->lchild);
		T->rchild=CreateBiTree(T->rchild);
	return T;}
}
void Preorder(BiTree T){
     if(T){
	 printf("%c",T->data);
	 Preorder(T->lchild);
	 Preorder(T->rchild);
	}
}
void Inorder(BiTree T){
    if(T){
	Inorder(T->lchild);
	printf("%c",T->data);
	Inorder(T->rchild);
	}
}
void Postorder(BiTree T){
    if(T){
	Postorder(T->lchild);
	Postorder(T->rchild);
	printf("%c",T->data);
	}
}
main(){
    BiTree T;
    T=CreateBiTree(T);
    Preorder(T);
    printf("\n");
    Inorder(T);
    printf("\n");
    Postorder(T);
    printf("\n");
}
