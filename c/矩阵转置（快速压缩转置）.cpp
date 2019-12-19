#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 12500
//��Ԫ��洢�ṹ
typedef struct{
    int i,j;//�У���
    int e;//Ԫ��ֵ
}Triple;
typedef struct{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;//�������������������
}TSMatrix;
int CreateSMatrix(TSMatrix &M)//����ϡ�����M
     {
       int x,m,n;
       int e,a;
       int k;
       printf("��������������,����,����Ԫ������");
       scanf("%d%d%d",&M.mu,&M.nu,&M.tu);
       M.data[0].i=M.mu; // Ϊ���±Ƚ�˳����׼��,��ʼ����Ԫ���һ��
       M.data[0].j=M.nu;
       M.data[0].e=M.tu;
       for(x=1;x<=M.tu;x++)//����0��������ѭ��
       {
         do
         {
           printf("�밴����˳�������%d������Ԫ�����ڵ���,��,Ԫ��ֵ��",x);
           scanf("%d%d%d",&m,&n,&e);
           k=0;
           if(m<1||m>M.mu||n<1||n>M.nu) // �л��г�����Χ
             k=1;//�������룬ֱ���ϸ�Ϊֹ
         }while(k);
         M.data[x].i=m;
         M.data[x].j=n;
         M.data[x].e=e;
       }
       for(a=0;a<=M.tu;a++)
           {
               printf("%d\t",M.data[a].i);
               printf("%d\t",M.data[a].j);
               printf("%d\t\n",M.data[a].e);
           }
        printf("\n");
       return 1;
     }
void FastTransposeSMatrix(TSMatrix M,TSMatrix &T)
    {
        T.mu = M.nu;
        T.nu = M.mu;
        T.tu = M.tu;
        T.data[0].i=T.mu; // Ϊ���±Ƚ�˳����׼������ʼ����һ��
        T.data[0].j=T.nu;
        T.data[0].e=T.tu;
        int a,col,i,*num,*cpot,p,q;
        num=(int*)malloc(100*sizeof(int));
        cpot=(int*)malloc(100*sizeof(int));
        if(T.tu)//����������num����ĸ�ֵ
        {
        for(col=1;col<=M.nu;col++)
            {num[col]=0;}
        for(i=1;i<=M.tu;i++)
            {col=M.data[i].j;//ѡȡ����
            ++num[col];//��1����
            }
        cpot[1]=1;//��ʼ����һ�е�cpot����
        for(col=2;col<=M.nu;col++)//���νo���е�cpot��ֵ
            cpot[col]=cpot[col-1]+num[col-1] ;
        for(p=1;p<=M.tu;p++)//ת�ò���
            {
              col=M.data[p].j;
              q=cpot[col];
              T.data[q].i=M.data[p].j;
              T.data[q].j=M.data[p].i;
              T.data[q].e=M.data[p].e;
              ++cpot[col];
            }
        }
        for(a=0;a<=T.tu;a++)
           {
               printf("%d\t",T.data[a].i);
               printf("%d\t",T.data[a].j);
               printf("%d\t\n",T.data[a].e);
           }
    }
    main()
{
    TSMatrix T;
    TSMatrix M;
    CreateSMatrix(M);
    FastTransposeSMatrix(M,T);
}
