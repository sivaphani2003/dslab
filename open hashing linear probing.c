/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int hash(int x)
{
    return x%10;
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
        j=i+1;
        while(j%10!=i)
        {
            if(a[j]==-1)
            {
                a[j]=x;
                flag=1;
                break;
            }
            j++;
        }
    }
    if (flag==0)
    {
        printf("No slot to insert element\n");
    }
}
void search(int a[10],int x)
{
    int flag=0,j;
    int i=hash(x);
    if (a[i]==x)
    {
        flag=1;
    }
    else
    {
        j=i+1;
        while(j%10!=i)
        {
            if (a[j]==x)
            {
                flag=1;
                break;
            }
            j++;
        }
    }
    if (flag)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found");
    }
}
void delete(int a[10],int x)
{
    int flag=0,j;
    int i=hash(x);
    if (a[i]==x)
    {
        a[i]=-1;
        flag=1;
    }
    else
    {
        j=i+1;
        while(j%10!=i)
        {
            if (a[j]==x)
            {
                a[j]=-1;
                flag=1;
                break;
            }
            j++;
        }
    }
    if (flag==0)
    {
        printf("Element not found to delete\n");
    }
}
void display(int a[10])
{
    int i;
    for (i=0;i<10;i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[10],i,x1,x2,x3,ch;
    for (i=0;i<10;i++)
    {
        a[i]=-1;
    }
    while(1)
    {
        printf("1:Insert\n2:Display\n3:Search\n4:Delete\n5:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter a value to insert\n");
                    scanf("%d",&x1);
                    do
                    {
                        insert(a,x1);
                        printf("Enter a value(Enter -1 to stop)\n");
                        scanf("%d",&x1);
                    }while(x1!=-1);
                    break;
            case 2: display(a);
                    break;
            case 3: printf("Enter element to search\n");
                    scanf("%d",&x2);
                    search(a,x2);
                    break;
            case 4: printf("Enter element to delete\n");
                    scanf("%d",&x3);
                    delete(a,x3);
                    display(a);
                    break;
            case 5: printf("You entered to exit so quitting\n");
                    exit(0);
            default:printf("Enter a valid choice\n");
                    break;
        }
    }
    return 0;
}

