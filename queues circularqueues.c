#include <stdio.h>
#include<stdlib.h>
#define max 5
int a[max],f=-1;
int r=-1;
void enqueue(int x)
{
    if(f==(r+1) % max)
    {
        printf("queue Overflow\n");
    }
    else
    {
        if(f==-1)
        {
            f=r=0;
        }
        else
        {
            r=(r+1)%max;
        }
        a[r]=x;
    }
}
int dequeue()
{
    if(f==-1)
    {
        return -1;
    }
    else
    {
        int x=a[f];
        if(f==r)
        {
            f=r=-1;
        }
        else
        {
            f=(f+1)%max;
        }
        return x;
    }
}
void display()
{
    if(f==-1)
    {
        printf("there is no elements in the queue");
    }
    else
    {
        int t=f;
        while(t!=r)
        {
            printf("%d\t ",a[t]);
            t=(t+1)%max;
        }
        if(t==r)
        {
            printf("%d\t",a[t]);
        }
        printf("\n");
    }
}
void main()
{
    int x,ch;
    while(1)
    {
        printf("enter the choice\n1:insert\n2:delete\n3:display\n4:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element you want to insert to your queue\n");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: x=dequeue();
                    if(x==-1)
                    {
                        printf("the queue is underflowed\n");
                    }
                    else
                    {
                        printf("the element %d is deleted out\n",x);
                    }
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:printf("enter the correct choice\n");
        }
    }
}
