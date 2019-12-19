#include<stdio.h>
#include<stdlib.h>
#define Stack_Init_Size 100
#define STACKINCREMENT 10
//atof �ַ���������
//atoi �ַ�������
//gcvt �������������ַ���
typedef struct stack//�������
    {
        char *base;
        char *top;
        int stacksize;
    }Sqstack;
typedef struct stack1//�������
    {
        float *base;
        float *top;
        int stacksize;
    }Sqlstack;
void Initstack1(Sqstack &S)//��ʼ��
    {
        S.base=(char *)malloc(Stack_Init_Size*sizeof(char));
        if(!S.base)  exit(1);
        S.top=S.base;
        S.stacksize=Stack_Init_Size;
    }
void Initstack2(Sqlstack &S)//��ʼ��
    {
        S.base=(float *)malloc(Stack_Init_Size*sizeof(float));
        if(!S.base)  exit(1);
        S.top=S.base;
        S.stacksize=Stack_Init_Size;
    }

void PUSH1(Sqstack &S,char e)
    {
         if(S.top-S.base>=S.stacksize)//����ջ��
         {
             S.base=(char *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(char));//�������ռ�
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
        if(S.top==S.base)//����ջ��
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
char Precede(char x1,char x2)//��������ȼ�����
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
 void check(char ch[])//����ƥ��
 {
     {   Sqstack s;
         Initstack1(s);
         char *p,e;
         p=ch;
         while(*p) // û����β
       switch(*p)
       {
         case '(':
         case '[':PUSH1(s,*p++);
                  break; // ��������ջ����p++
         case ')':
         case ']':if(s.top!=s.base) // ջ����
                  { pop1(s,e); // ����ջ��Ԫ��
                    if(*p==')'&&e!='('||*p==']'&&e!='[') // ������ջ��Ԫ����*p�����
                    {
                      printf("�������Ų����\n");
                      exit(1);
                    }
                    else
                    {
                      p++;
                      break;
                    }
                  }
                  else // ջ��
                  {
                    printf("ȱ��������\n");
                    exit(1);
                  }
         default: p++; //�����ַ�������ָ�������
       }
       if(s.top==s.base) //�ַ�������ʱջ��
         printf("����ƥ��\n");
       else
         printf("ȱ��������\n");
   }
 }
int In(char s)//�ж�����������ǲ�����
    {
        if(s=='+'||s=='-'||s=='*'||s=='/'||s=='('||s==')'||s=='#')
            return 0;
        else
            return 1;
    }
float Operate(float a,char theta,float b)//�����Ӻ���
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
                printf("����ʵ��");
                exit(0);
            }
        }
    }
float EvaluateException()
{       Sqstack OPTR;Sqlstack OPND;
        Initstack2(OPND);
        Initstack1(OPTR);
        //��ʼ������ջ
        char *c,x,theta,z;
        c=(char *)malloc(100*sizeof(char ));
        float a,b,y;
        PUSH1(OPTR,'#');
        gets(c);
        while(*c!='#'||Gettop1(OPTR)!='#')
    {
            if(In(*c))//������
            {
                y=atof(c);
                PUSH2(OPND,y);
                gets(c);//������һ���ַ���
            }
            else{
        switch(Precede(Gettop1(OPTR),*c))//�Ƚ�����������ȼ�
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
        printf("��������ʽ(����#��β)��");
        gets(a);
        check(a);
        x=EvaluateException();
        printf("���ʽ�Ľ���ǣ�%.3f\n",x);
    }
