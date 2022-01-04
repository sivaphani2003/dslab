#include <stdio.h>
#include<stdlib.h>
#define max 5
int a[max],top=-1;
void push(int x)
{
    if(top==max-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        a[++top]=x;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack UnderFlow\n");
        return -1;
    }
    else
    {
        return a[top--];
    }
}
int peek()
{
    return a[top];
}
void display()
{
    if(top==-1)
    {
        printf("there is no elements in the stack");
    }
    else
    {
        for(int i=0;i<top+1;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}
void main()
{
    int x,ch;
    while(1)
    {
        printf("enter the choice\n1:push\n2:pop\n3:peek\n4:display\n5:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element you want to push to your stack\n");
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2: x=pop();
                    printf("the element %d is popped out\n",x);
                    break;
            case 3: x=peek();
                    printf("tne element %d is at the top of the stack\n",x);
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
            default:printf("enter the correct choice\n");
        }
    }
}
