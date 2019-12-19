#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct BiThrNode
{
	float weight;
	int parent,lchild,rchild;
	char data;
} HTNode,*HuffmanTree;
typedef char** HuffmanCode;
void Select(HuffmanTree HT,int n,int &s1,int &s2)//找parent=0最小的两个数
{
    float *a;
    int x=1;
     s1=0,s2=0;
    a=(float *)malloc(100*sizeof(float));
    for(int k=1;k<=n;k++)//将parent=0的weight赋给新的数组a
    {
        if(HT[k].parent==0)
        {
        a[x]=HT[k].weight;
        x++;
        }
    }
    x--;
    for(int i=1; i<=x; i++)//给a数组从小到大排序
    {
        for(int j=1; j<=x-i; j++)
        {
            if(a[j] > a[j+1])
            {
                float temp = a[j];
                a[j] =a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=1;i<=n;i++)//找与a数组最小两项相匹配的HT中的位置
    {
        int count=0;
        if(s1==0&&HT[i].parent==0)//s1确保s1还没有被赋值
    {
        if(a[1]==HT[i].weight)
            {s1=i;
            count++;}
    }
        if(count==0&&s2==0&&a[2]==HT[i].weight&&HT[i].parent==0)//count作用保证给s1赋的值不再给s2赋值
            s2=i;
    }
}
void CreaHuffman(HuffmanTree &HT,float *w,int n,char *ch)
{
    if(n<=1) return;
     int i,k,s1=0,s2=0;
    int m=2*n-1;
    int x=0;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    for(i=1;i<=n;i++)//给存在的n项初始化
        {
            HT[i].weight=*(w+i-1);
            HT[i].data=*(ch+i-1);
            HT[i].parent=0;
            HT[i].lchild=0;
            HT[i].rchild=0;
        }
    for(;i<=m;i++)//给剩余的n-1项初始化
        {
                HT[i].weight=0;
                HT[i].data='0';
                HT[i].parent=0;
                HT[i].lchild=0;
                HT[i].rchild=0;
        }
    for(i=n+1;i<=m;i++)//形成整个霍夫曼树
        {
            Select(HT,i-1,s1,s2);
            HT[s1].parent=i;
            HT[s2].parent=i;
            HT[i].lchild=s1;
            HT[i].rchild=s2;
            HT[i].weight=HT[s1].weight+HT[s2].weight;
        }
}
void Huffmancoding(HuffmanTree &HT,HuffmanCode &HC,int n)//编码
{
    char *cd;
    int i,start,c;
    HC=(HuffmanCode)malloc((n+1)*sizeof(char *));//二级指针，存多个cd字符串数组
    cd=(char *)malloc(n*sizeof(char));//暂时存编码
    for(i=1;i<=n;i++)
    {
        start=n-1;
        int f=HT[i].parent;
        for(c=i;f!=0;c=f,f=HT[f].parent)
            if(HT[f].lchild==c) cd[--start]='0';
            else
                cd[--start]='1';
            HC[i]=(char *)malloc((n-start)*sizeof(char));
            strcpy(HC[i],&cd[start]);
    }
    free(cd);
}
char* DispHuffman(HuffmanTree HT,char s)
{
    HuffmanCode HC;
    Huffmancoding(HT,HC,8);
    for(int i=1;i<=8;i++)
    {
        if(HT[i].data==s)
    {
        printf("\t\t%c\t%s\n",s, HC[i]);
        return HC[i];
    }
    }
}
void wpl(HuffmanTree HT,int n)
{   float s=0;int c;
    HuffmanCode HC;
    Huffmancoding(HT,HC,8);
    for(int i=1;i<=8;i++)
    {
        int count=0;//记载此数据所在层
        for(int k=0;k<4;k++)
        {
            if(HC[i][k]=='0'||HC[i][k]=='1')
            {
                count++;
            }
        }
        s=s+count*HT[i].weight;//累加wpl
    }
    printf("\t%f",s);
}
main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    float w[8]={0.05,0.29,0.07,0.08,0.14,0.23,0.03,0.11};
    char ch[8]={'a','b','c','d','e','f','h','i'};
    CreaHuffman(HT,w,8,ch);
    printf("字母及其对应值：\n");
    for(int i=0;i<8;i++)
    DispHuffman(HT,ch[i]);
    printf("WPL值为：\n");
    wpl(HT,8);
}
