#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 20
int a[MAX] ,top=-1;
int operation(int op1,int op2,char c)
{
    switch(c)
    {
        case '^': return (pow(op1,op2));
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '%': return (op1%op2);
        case '+': return (op1+op2);
        case '-': return (op1-op2);
    }
}
void push(int ch)
{
    a[++top]=ch;
}
int pop()
{
    return a[top--];
}
int main()
{
    char postfix[MAX],c;
    int op1,op2,res,i=0;
    printf("enter the postfix expression : ");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        c=postfix[i];
        if(isdigit(c))
        {
            push(c-'0');
        }
        else
        {
            op2=pop();
            op1=pop();
            res=operation(op1,op2,c);
            push(res);
        }
        i++;
    }
    printf("The result of postfix expression %d",a[top]);
    return 0;
}
