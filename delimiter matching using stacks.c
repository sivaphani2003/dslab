#include<stdio.h>
#define MAX 20
char a[MAX];
int top=-1;
void push(char ch)
{
    a[++top]=ch;
}
char pop()
{
    return a[top--];
}
int main()
{
    char exp[MAX],c,x;
    int flag=1,i=0;
    printf("enter the expression for delimiter matching ");
    scanf("%s",exp);
    while(exp[i]!='\0')
    {
        c=exp[i];
        if(c=='('||c=='['||c=='{')
        {
            push(c);
        }
        else if(c==')'||c==']'||c=='}')
        {
            if(top==-1)
            {
                flag=0;
                break;
            }
            else
            {
                x=pop();
                if ( x == '(' && c==')' ||
                x=='['&&c==']'||
                x=='{'&&c=='}')
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        i++;
    }
    if(top!=-1)
    {
        flag=0;
    }
    if(flag==1)
    {
        printf("Matched");
    }
    else
    {
        printf("Not Matched");
    }
    return 0;
}
