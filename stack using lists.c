#include <stdio.h>
#include<stdlib.h>
#define max 5
struct stack
{
    int a[max];
    int top;
};
void push(int x, struct stack *s)
{
    if(s->top==max-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->a[++(s->top)]=x;
    }
}
int pop(struct stack *s)
{
    if(s->top==-1)
    {
        printf("Stack UnderFlow\n");
        return -1;
    }
    else
    {
        return s->a[(s->top)--];
    }
}
int peek(struct stack *s)
{
    return s->a[s->top];
}
void display(struct stack *s)
{
    if(s->top==-1)
    {
        printf("there is no elements in the stack\n");
    }
    else
    {
        for(int i=0;i<(s->top)+1;i++)
        {
            printf("%d ",s->a[i]);
        }
        printf("\n");
    }
}
void main()
{
    int x,ch;
    struct stack *s1;
    s1->top=-1;
    while(1)
    {
        printf("enter the choice\n1:push\n2:pop\n3:peek\n4:display\n5:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element you want to push to your stack\n");
                    scanf("%d",&x);
                    push(x,s1);
                    break;
            case 2: x=pop(s1);
                    if(x!=-1)
                    {
                        printf("the element %d is popped out\n",x);
                    }
                    break;
            case 3: x=peek(s1);
                    printf("tne element %d is at the top of the stack\n",x);
                    break;
            case 4: display(s1);
                    break;
            case 5: exit(0);
            default:printf("enter the correct choice\n");
        }
    }
}
