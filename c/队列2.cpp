#include<stdio.h>
#include<stdlib.h>
#define maxsize 50
typedef struct SqQueue{
	int data[maxsize];
	int front;//����ָ��
	int rear;//��βָ��
}SqQueue;
//����ѭ������
SqQueue initQueue(SqQueue *sq){
	sq=(SqQueue *)malloc(sizeof(SqQueue));
	if(sq ==NULL){
		exit(1);
	}
	sq->rear=sq->front=0;
	return *sq;
}
//�ж�ѭ�������Ƿ�Ϊ��
int isEmpty(SqQueue qu){
	return (qu.front ==qu.rear?1:0);
}
//Ԫ�ؽ�ѭ������
int enQueue(SqQueue *qu,int x){
	if((qu->rear+1)%maxsize ==qu->front){
		return 0;
	}
	qu->rear=(qu->rear+1)%maxsize;
	qu->data[qu->rear]=x;
	return 1;
}
//Ԫ�س�ѭ������
int deQueue(SqQueue *qu,int *y){
	if(qu->rear ==qu->front){
		return 0;
	}
	*y=qu->data[qu->front];
	qu->front=(qu->front+1)%maxsize;
	return 1;
}
//��ӡѭ������
int printQueue(SqQueue *qu){
	if(qu->rear ==qu->front){
		return 0;
	}
	while(qu->rear !=qu->front){
		qu->front=(qu->front+1)%maxsize;
		printf("��ǰ����ֵ=%d\n",qu->data[qu->front]);
	}
	return 1;
}
int main(){
	int y=0;
	SqQueue *sq ;
	initQueue(sq);
	enQueue(sq,1);
	enQueue(sq,2);
	enQueue(sq,3);
	enQueue(sq,4);
	deQueue(sq,&y);
	printQueue(sq);
	printf("��ǰ��front=%d\n",sq->front);
	printf("��ǰ��rear=%d\n",sq->rear);

}
