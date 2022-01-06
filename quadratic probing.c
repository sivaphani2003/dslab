#include <stdio.h>
#include <stdlib.h>
int k=1;
int z;
int hash(int x)
{
        return x%10;
}
int hash1(int a[10],int x,int r)
{
        int i=x%10;
        int h=z%10;
        if (a[i]==-1)
        {
                return i;
        }
        else
        {
                i=h+(r*r);
                return hash1(a,i,r+1);
        }
}
void insert(int a[10],int x)
{
    int flag=0,j;
    int i=hash(x);
    if (a[i]==-1)
    {
            a[i]=x;
            flag=1;
    }
    else
    {
            j=hash1(a,x,1);
            a[j]=z;
            flag=1;
    }
    if (flag==0)
    {
            printf("No place to insert element\n");
    }
}
void search(int a[10],int x)
{
        int i,flag=0;
        for(i=0;i<10;i++)
        {
                if (a[i]==x)
                {
                        flag=1;
                        break;
                }
        }
        if(flag)
        {
                printf("Element found\n");
        }
        else
        {
                printf("Element not found\n");
        }
}
void display(int a[10])
{
        int i;
        for (i=0;i<10;i++)
        {
                printf("%2d  ",a[i]);
        }
        printf("\n");
}
int main()
{
        int a[10],x,x1;
        for (int i=0;i<10;i++)
        {
                a[i]=-1;
        }
        printf("Enter data\n");
        scanf("%d",&x);
        while(x!=-1)
        {
                z=x;
                insert(a,x);
                printf("Enter data\n");
                scanf("%d",&x);
        }
        display(a);
        printf("Enter element to search\n");
        scanf("%d",&x1);
        search(a,x1);
        return 0;
}
