#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define String_Init_Size 100
#define ERROR 1
typedef struct{
    char *ch;
    int length;
}HString;
void StrAssign(HString &T,char *chars)//字符串赋值
    {
        int i,j;
        if(T.ch)//防护措施，清除字符串原先存在的内存
        {
            free(T.ch);
        }
        i=strlen(chars);
        if(!i)//检查要输入的字符串是否为空
        {
            T.ch=NULL;
            T.length=0;
        }
        else{
                T.ch=(char *)malloc(String_Init_Size*sizeof(char));//申请空间
                if(!T.ch) exit(1);
                for(j=0;j<i;j++)//赋值
                    {
                        T.ch[j]=chars[j];
                        T.length=i;
                    }
            }
            T.ch[T.length]='\0';
    }
//无用
/*void Concat(HString &T,HString S,HString Q)//连接S，Q，构造形成字符串T
    {   int i,j;
        T.length=S.length+Q.length;
        if(!T.ch)
            {
                free(T.ch);
            }
        T.ch=(char *)malloc(String_Init_Size*sizeof(char));
        for(j=0;j<S.length;j++)
            {
                T.ch[j]=S.ch[j];
            }
        for(i=0;i<Q.length;i++)
            {
                T.ch[S.length+i]=Q.ch[i];
            }
    }
void SubString(HString &S,HString T,int pos,int len)//将字符串T第POS位置之后的子串赋值给字符串T
    {
        if(pos<1 || pos>S.length || len<0 || len>S.length-pos+1)
       exit(1);
        int i;
        if(S.ch)
            {
                free(S.ch);
            }
        if(!len)
            {
                S.ch=NULL;
                S.length=0;
            }
        S.ch=(char *)malloc(String_Init_Size*sizeof(char));
        for(i=0;i<len;i++)
            {
                S.ch[i]=T.ch[i+pos-1];
                S.length=len;
            }
    }*/
void RepStr1(HString s,int i,int j,HString t,HString &str)  //1.在串s中，将第i(1≤i≤StrLength(s))个字符开始的j个字符构成的子串用串t替换
{                                                           //，并返回产生的新串
        int k;
        if(i<=0||i>s.length||i+j-1>s.length)//被替换的指定长度的字符串超出总长度
            {
                printf("Unreplaceable");
                exit(1);
            }
        for(k=0;k<i-1;k++)//给i之前的字符串copy下来
        {
            str.ch[k]=s.ch[k];
        }
        for(k=0;k<t.length;k++)//赋值第i到j的字符串为新的字符串
        {
            str.ch[k+i-1]=t.ch[k];
        }
        for(k=i+j-1;k<s.length;k++)//赋值j之后的字符串为原先字符串j之后的字符串
        {
            str.ch[k-j+t.length]=s.ch[k];
        }
        str.length=s.length-j+t.length;//给输出的新的字符串赋予它的长度
        str.ch[str.length]='\0';
    }
void get_next(HString &S,int next[])//针对模式串，这个程序next数组下标从0开始，即往前推一位
{
    int i=0;
    int j=-1;
    next[0]=-1;
    while(i<S.length)
    {
        if(j==-1||S.ch[i]==S.ch[j])
        {
            i++;j++;
            next[i]=j;//存第i位前有多少位的公共前后缀
        }
        else j=next[j];
    }
}
int Index_KMP(HString &S,HString &T,int pos)//KMP算法
    {
        int i=pos-1;
        int j=0;
        int *next;
        next=(int *)malloc(100*sizeof(int));
        get_next(T,next);//生成T的next数组
        while(i<S.length&&j<T.length)
        {
            if(j==-1||S.ch[i]==T.ch[j]){
                ++i,++j;
                        }
                else
                j=next[j];
        }
        if(j>=T.length) return i-T.length+1;
        else return 0;
    }
void RepStr2(HString &S,HString T,HString Q)//T被替换，Q替换
{
        int k,x,num=0;
        HString L;
        L.ch=(char *)malloc(1000*sizeof(char));
        L.length=0;
        for(x=0;x<S.length;x++)//将S的字符串值赋给L，使S不发生改变
        {
            L.ch[x]=S.ch[x];
            L.length=S.length;
        }
        if(T.length==Q.length)//等于
        {
            while(Index_KMP(S,T,1))
            {
            int i=Index_KMP(S,T,1);
            for(k=0;k<Q.length;k++)
            {
                S.ch[i+k-1]=Q.ch[k];
            }
            S.ch[S.length]='\0';
            }
        }
        else if(T.length>Q.length)//大于
        {
            while(Index_KMP(S,T,1))
            {
                HString O=S;
                int m=Index_KMP(S,T,1);
                for(k=0;k<Q.length;k++)
                {
                    S.ch[m+k-1]=Q.ch[k];
                }
                for(k=m+T.length-1;k<O.length;k++)
                {
                    S.ch[Q.length+k-T.length]=L.ch[k];
                }
                S.length=O.length+Q.length-T.length;
                S.ch[S.length]='\0';
            }
        }
        else{
            while(Index_KMP(S,T,1))//小于
            {
                int l=Index_KMP(S,T,1);
                for(k=0;k<Q.length;k++)
                {
                    S.ch[l+k-1]=Q.ch[k];
                }
                for(k=l+T.length-1-num;k<=L.length;k++)
                {
                    S.ch[Q.length+k-T.length+num]=L.ch[k];
                }
                S.length=S.length+Q.length-T.length;
                S.ch[S.length]='\0';
                num++;
       }
       }
    }
main()
{
        HString S,l,q,k;
        system("color f0");
        int len,x,y,z;
        char *chars,*s,*m;
        chars=(char *)malloc(1000*sizeof(char));
        printf("please input the character string:");
        gets(chars);
        printf("please input the number of replacing plan(1 or 2):");
        scanf("%d",&z);
        getchar();
    if(z==1)
        {
            s=(char *)malloc(1000*sizeof(char));
            m=(char *)malloc(1000*sizeof(char));
            printf("please input the number where the replacing begining:");
            scanf("%d",&x);
            getchar();
            printf("please input the number of replaced letters:");
            scanf("%d",&y);
            getchar();
            printf("please input what you want to replace:");
            gets(m);
            StrAssign(S,chars);
            StrAssign(q,m);
            StrAssign(l,s);
            RepStr1(S,x,y,q,l);
            printf("The changed character string:%s",l);
        }
    else if(z==2)
        {
            s=(char *)malloc(1000*sizeof(char));
            m=(char *)malloc(1000*sizeof(char));
            printf("please input what you want to be replaced:");
            gets(s);
            printf("please input what you want to replace:");
            gets(m);
            StrAssign(S,chars);
            StrAssign(l,s);
            StrAssign(q,m);
            RepStr2(S,l,q);
            printf("The changed character string:%s",S);
        }
}
