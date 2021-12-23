
#include <stdio.h>
int a[10];
int n;
void read()
{
    int i;
    printf("Enter array elementes\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%3d",a[i]);
    }
}
void insert(int pos,int ele)
{
    int i;
    for(i=n-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    n++;
    a[pos-1]=ele;
}
void sort()
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void search(int se)
{
    int i,flag=0,position;
    for(i=0;i<n;i++)
    {
        if (a[i]==se)
        {
            flag=1;
            position=i;
            break;
        }
    }
    if (flag==1)
    {
        printf("Element found at position %d\n",position);
    }
    else
    {
        printf("Element not found\n");
    }
}
void delete(int del)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        if (a[i]==del)
        {
            for (j=i;j<n-1;j++)
            {
                a[j]=a[j+1];
            }
            n--;
            break;
        }
    }
}
void reverse()
{
    int i,j,t;
    for(i=0,j=n-1;i<j;i++,j--)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}
void RemoveDuplicates()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (a[i]==a[j])
            {
                for(k=j;k<n-1;k++)
                {
                    a[k]=a[k+1];
                }
                n--;
                j--;
            }
        }
    }
}
int main()
{
    int i,pos,ele,ch,del,se;
    printf("Enter your choice\n");
    printf("1:read\t2:display\t3:insert\t4:sort\t5:search\t6:delete\t7:reverse\t8:RemoveDuplicates\t9:exit\n");
    scanf("%d",&ch);
    printf("Enter the size\n");
    scanf("%d",&n);
    while(ch!=9)
    {
        switch(ch)
        {
            case 1:read();
                   break;
            case 2:display();
                   break;
            case 3:printf("Enter position to insert\n");
                   scanf("%d",&pos);
                   printf("Enter element to insert\n");
                   scanf("%d",&ele);
                   insert(pos,ele);
                   display();
                   break;
            case 4:printf("\nBefore sorting\n");
                   display();
                   sort();
                   printf("\nAfter sorting\n");
                   display();
                   break;
            case 5:printf("Enter element to search\n");
                   scanf("%d",&se);
                   search(se);
                   break;
            case 6:printf("Enter element to delete\n");
                   scanf("%d",&del);
                   printf("\nBefore deletion\n");
                   display();
                   delete(del);
                   printf("\n");
                   printf("\nAfter deletion\n");
                   display();
                   break;
            case 7:printf("\nBefore reversing\n");
                   display();
                   reverse();
                   printf("\n");
                   printf("\nAfter reversing\n");
                   display();
                   break;
            case 8:printf("\nBefore removing duplicates\n");
                   display();
                   RemoveDuplicates();
                   printf("\n");
                   printf("\nAfter removing duplicates\n");
                   display();
                   break;
            default:printf("Enter a valid input");
                   break;
        }
        printf("\n");
        printf("1:read\t2:display\t3:insert\t4:sort\t5:search\t6:delete\t7:reverse\t8:RemoveDuplicates\t9:exit\n");
        scanf("%d",&ch);
    }
    return 0;
}

