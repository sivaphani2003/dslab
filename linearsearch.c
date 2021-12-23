#include <stdio.h>
#include <stdlib.h>
void linearsearch(int a[20],int n,int x)
{
        int i,flag=0;
        for(i=0;i<n;i++)
        {
                if(a[i]==x)
                {
                        flag=1;
                        break;
                }
        }
        if (flag)
        {
                printf("Element found\n");
        }
        else
        {
                printf("Element not found\n");
        }
}
void main()
{
        int n,i,ele;
        printf("Enter size of array\n");
        scanf("%d",&n);
        int a[n];
        for (i=0;i<n;i++)
        {
                printf("Enter %d element\n",i+1);
                scanf("%d",&a[i]);
        }
        printf("Enter element to search\n");
        scanf("%d",&ele);
        linearsearch(a,n,ele);
}
