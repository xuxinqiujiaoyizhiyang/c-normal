#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 12500

//三元组存储结构
typedef struct{
    int i,j;//行，列
    int e;//元素值
}Triple;
typedef struct{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;//行数，列数，非零个数
}TSMatrix;
int CreateSMatrix(TSMatrix &M)
     { //创建稀疏矩阵M
       int x,m,n;
       int e,a;
       int k;
       printf("请输入矩阵的行数,列数,非零元素数：");
       scanf("%d%d%d",&M.mu,&M.nu,&M.tu);
       M.data[0].i=M.mu; // 为以下比较顺序做准备
       M.data[0].j=M.nu;
       M.data[0].e=M.tu;
       for(x=1;x<=M.tu;x++)
       {
         do
         {
           printf("请按行序顺序输入第%d个非零元素所在的行,列,元素值：",x);
           scanf("%d%d%d",&m,&n,&e);
           k=0;
           if(m<1||m>M.mu||n<1||n>M.nu) // 行或列超出范围
             k=1;
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
       return 1;
     }
void TransposeSMatrix(TSMatrix M,TSMatrix &T)
{
    T.mu=M.nu;
    T.nu=M.mu;
    T.tu=M.tu;
    int q,col,p,a;
       T.data[0].i=T.mu; // 为以下比较顺序做准备
       T.data[0].j=T.nu;
       T.data[0].e=T.tu;
    if(T.tu){
        q=1;
        for(col=1;col<M.nu;col++)//转置过程，存到新的三元组中
        {
            for(p=1;p<=M.tu;++p)
                if(M.data[p].j==col)
                {
                    T.data[q].i=M.data[p].j;
                    T.data[q].j=M.data[p].i;
                    T.data[q].e=M.data[p].e;
                    ++q;
                }
        }
        for(a=0;a<=T.tu;a++)
           {
               printf("%d\t",T.data[a].i);
               printf("%d\t",T.data[a].j);
               printf("%d\t\n",T.data[a].e);
           }
    }
}
main()
{
    TSMatrix T;
    TSMatrix M;
    CreateSMatrix(M);
    TransposeSMatrix(M,T);
}
