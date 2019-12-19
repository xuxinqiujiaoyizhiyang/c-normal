#include<stdio.h>
#include<stdlib.h>
#define Stack_Init_Size 100
#define STACKINCREMENT 10
//atof 字符到浮点数
//atoi 字符到整数
//gcvt 将浮点数换成字符串
typedef struct stack//存运算符
    {
        char *base;
        char *top;
        int stacksize;
    }Sqstack;
typedef struct stack1//存操作数
    {
        float *base;
        float *top;
        int stacksize;
    }Sqlstack;
void Initstack1(Sqstack &S)//初始化
    {
        S.base=(char *)malloc(Stack_Init_Size*sizeof(char));
        if(!S.base)  exit(1);
        S.top=S.base;
        S.stacksize=Stack_Init_Size;
    }
void Initstack2(Sqlstack &S)//初始化
    {
        S.base=(float *)malloc(Stack_Init_Size*sizeof(float));
        if(!S.base)  exit(1);
        S.top=S.base;
        S.stacksize=Stack_Init_Size;
    }

void PUSH1(Sqstack &S,char e)
    {
         if(S.top-S.base>=S.stacksize)//检验栈满
         {
             S.base=(char *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(char));//申请多余空间
             if(!S.base) exit(1);
             S.top=S.base+S.stacksize;
             S.stacksize+=STACKINCREMENT;
         }
         *S.top=e;
         S.top++;
    }
void PUSH2(Sqlstack &S,float e)
    {
         if(S.top-S.base>=S.stacksize)
         {
             S.base=(float *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(float));
             if(!S.base) exit(1);
             S.top=S.base+S.stacksize;
             S.stacksize+=STACKINCREMENT;
         }
         *S.top=e;
         S.top++;
    }

void pop1(Sqstack &S,char &e)
    {
        if(S.top==S.base)//检验栈空
            exit(1);
        else
        {
            S.top--;
            e=*S.top;
        }
    }
void pop2(Sqlstack &S,float &e)
    {
        if(S.top==S.base)
            exit(1);
        else
        {
            S.top--;
            e=*S.top;
        }
    }
char  Gettop1(Sqstack &S)
    {   char e;
        if(S.base==S.top)
            return 1;
        e=*(S.top-1);
        return e;
    }
float  Gettop2(Sqlstack &S)
    {   float e;
        if(S.base==S.top)
            return 1;
        e=*(S.top-1);
        return e;
    }
char Precede(char x1,char x2)//运算符优先级排序
    {
        if(x1=='+'||x1=='-')
            x1='+';
        if(x1=='*'||x1=='/')
            x1='*';
        switch(x1)
        {
            case '+':
            if(x2=='+'||x2=='-'||x2==')'||x2=='#')  return('>');
            return ('<');
            case '*':
            if(x2=='(') return ('<');
            return ('>');
            case '(':
            if(x2==')') return('=');
            return('<');
            case ')':
            return('>');
            case '#':
            if(x2=='#') return('=');
            return ('<');
            default:
            exit(0);
        }
    }
 void check(char ch[])//括号匹配
 {
     {   Sqstack s;
         Initstack1(s);
         char *p,e;
         p=ch;
         while(*p) // 没到串尾
       switch(*p)
       {
         case '(':
         case '[':PUSH1(s,*p++);
                  break; // 左括号入栈，且p++
         case ')':
         case ']':if(s.top!=s.base) // 栈不空
                  { pop1(s,e); // 弹出栈顶元素
                    if(*p==')'&&e!='('||*p==']'&&e!='[') // 弹出的栈顶元素与*p不配对
                    {
                      printf("左右括号不配对\n");
                      exit(1);
                    }
                    else
                    {
                      p++;
                      break;
                    }
                  }
                  else // 栈空
                  {
                    printf("缺乏左括号\n");
                    exit(1);
                  }
         default: p++; //其它字符不处理，指针向后移
       }
       if(s.top==s.base) //字符串结束时栈空
         printf("括号匹配\n");
       else
         printf("缺乏右括号\n");
   }
 }
int In(char s)//判断是运算符还是操作数
    {
        if(s=='+'||s=='-'||s=='*'||s=='/'||s=='('||s==')'||s=='#')
            return 0;
        else
            return 1;
    }
float Operate(float a,char theta,float b)//运算子函数
    {   switch(theta)
        {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            if(b!=0)
            {
                return a/b;
            }
            else
            {
                printf("不能实现");
                exit(0);
            }
        }
    }
float EvaluateException()
{       Sqstack OPTR;Sqlstack OPND;
        Initstack2(OPND);
        Initstack1(OPTR);
        //初始化两个栈
        char *c,x,theta,z;
        c=(char *)malloc(100*sizeof(char ));
        float a,b,y;
        PUSH1(OPTR,'#');
        gets(c);
        while(*c!='#'||Gettop1(OPTR)!='#')
    {
            if(In(*c))//操作数
            {
                y=atof(c);
                PUSH2(OPND,y);
                gets(c);//输入下一个字符串
            }
            else{
        switch(Precede(Gettop1(OPTR),*c))//比较运算符的优先级
        {
        case'<':
            PUSH1(OPTR,*c);
                gets(c);
            break;
        case '=':
           pop1(OPTR,x);
            gets(c);
            break;
        case'>':
            pop1(OPTR,theta);
            pop2(OPND,a);
            pop2(OPND,b);
            PUSH2(OPND,Operate(a,theta,b));
            break;
            }
        }
    }
      return Gettop2(OPND);
}
main()
    {
        char *a;
        float x;
        a=(char*)malloc(10*sizeof(char));
        printf("请输入表达式(请以#结尾)：");
        gets(a);
        check(a);
        x=EvaluateException();
        printf("表达式的结果是：%.3f\n",x);
    }
