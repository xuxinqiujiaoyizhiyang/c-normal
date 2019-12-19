#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define String_Init_Size 100
#define ERROR 1
typedef struct{
    char *ch;
    int length;
}HString;
void menu()
{
 int n;
 printf("\n\n\t\t*******************************************************\n");
 printf("\t\t**   1.新建文件                                      **\n");
 printf("\t\t**   2.删除文件                                      **\n");
 printf("\t\t**   3.查看文件                                      **\n");
 printf("\t\t**   4.字符串替换                                    **\n");
 printf("\t\t**   5.指定字符串个数查找                            **\n");
 printf("\t\t**   6.退出程序                                      **\n");
 printf("\t\t*******************************************************\n");
 printf("\t\t     您的输入：");
    fflush(stdin);
}
void startFILE()//新建
{
    FILE *fp;
    char ch,filename[10];
    printf("请输入文件名：");
    scanf("%s",filename);
    printf("请输入文件内容：");
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("不能打开");
        exit(0);
    }
    ch=getchar();
    ch=getchar();
    while(ch!='#')
    {
        fputc(ch,fp);
        ch=getchar();
    }
   // putchar(10);
    fclose(fp);
}
void readFILE()//查看
{
    FILE *fp;
    char ch;
    char filename[10];
    printf("请输入要打开的文件名称：");
    scanf("%s",filename);
    fp=fopen(filename,"rb");
    while(!feof(fp))//检验文件是否结束
    {
        ch=fgetc(fp);
        putchar(ch);
    }
    fclose(fp);
}
void StrAssign(HString &T,char *chars)//字符串赋值
    {
        int i,j;
        if(T.ch)
        {
            free(T.ch);
        }
        i=strlen(chars);
        if(!i)
        {
            T.ch=NULL;
            T.length=0;
        }
        else{
                T.ch=(char *)malloc(1000*sizeof(char));
                if(!T.ch) exit(1);
                for(j=0;j<i;j++)
                    {
                        T.ch[j]=chars[j];
                        T.length=i;
                    }
            }
            T.ch[T.length]='\0';
    }
void get_next(HString &S,int next[])//模式串
{
    int i=0;
    int j=-1;
    next[0]=-1;
    while(i<S.length)
    {
        if(j==-1||S.ch[i]==S.ch[j])
        {
            i++;j++;
            next[i]=j;
        }
        else j=next[j];
    }
}
int Index_KMP(HString &S,HString &T,int pos)//KMP算法
    {
        int i=pos-1;
        int j=0;
        int *next;
        next=(int *)malloc(1000*sizeof(int));
        get_next(T,next);
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
void RepStr2(HString &S,HString T,HString Q)
{
        int k,x,num=0;
        HString L;
        L.ch=(char *)malloc(1000*sizeof(char));
        L.length=0;
        for(x=0;x<S.length;x++)
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
    void insertarray(char *ch)//替换
    {
        FILE *fp;
        char s[100],m[100];
        char filename[10];
        ch=(char *)malloc(1000*sizeof(char));
        printf("请输入要打开的文件：");
        scanf("%s",filename);
        fp=fopen(filename,"rb");
        fgets(ch,1000,fp);
        printf("文件内容为：%s",ch);
        printf("请输入要被替换的字符串：");
        scanf("%s",s);
        printf("请输入要替换成的字符串：");
        scanf("%s",m);
        HString S,l,q,k;
        StrAssign(S,ch);
        StrAssign(l,s);
        StrAssign(q,m);
        RepStr2(S,l,q);
        printf("文件内的新内容：%s",S);
        fclose(fp);
    }
void Searchstrign(char *ch)//查找
{
        FILE *fp;
        char s[100];
        int i=0;
        int k,n;
        char filename[10];
        ch=(char *)malloc(1000*sizeof(char));
        printf("请输入要打开的文件：");
        scanf("%s",filename);
        fp=fopen(filename,"rb");
        fgets(ch,1000,fp);
        printf("文件内容为：%s",ch);
        printf("请输入要查找的字符串：");
        scanf("%s",s);
        HString S,l;
        StrAssign(S,ch);
        StrAssign(l,s);
        while(Index_KMP(S,l,1))
        {
            n=Index_KMP(S,l,1);
            for(k=0;k<S.length-n;k++)
            {
                S.ch[k]=S.ch[n+k];
            }
            S.length=S.length-n;
            S.ch[S.length]='\0';
            i++;//计数器
        }
        printf("字符串出现的次数为%d",i);
        fclose(fp);
}
main()
{
        int num,i;
        char *ch;
        ch=(char *)malloc(1000*sizeof(char));
        system("color f0");
        while(1)
        {
            menu();
            scanf("%d",&num);
            system("cls");
            switch(num)
            {
            case 1:
               startFILE();
               system("cls");
               break;
            case 2:
                char filename[80];
                printf("The file to delete:");
                scanf("%s",filename);
                if( remove(filename) == 0 )
                printf("Removed %s.", filename);
            else
                perror("remove");
                printf("\n按1返回菜单:");
                scanf("%d",&i);
                if(i==1)
                {
                system("cls");
                i=0;
                break;
                }
            case 3:
                readFILE();
                printf("\n按1返回菜单:");
                scanf("%d",&i);
                if(i==1)
                {
                system("cls");
                i=0;
                break;
                }
            case 4:
                insertarray(ch);
                printf("\n按1返回菜单:");
                scanf("%d",&i);
                if(i==1)
                {
                system("cls");
                i=0;
                break;
                }
            case 5:
            Searchstrign(ch);
            printf("\n按1返回菜单:");
                scanf("%d",&i);
                if(i==1)
                {
                system("cls");
                i=0;
                break;
                }
            case 6:
                printf("感谢使用！");
                exit(0);
            }
        }
}
