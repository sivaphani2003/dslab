#include<stdio.h>
void selectionsort(int a[30], int n)
{
    int i,temp,j;
    int minps=0;
    for(i=0;i<n;i++)
    {
        minps=i;
        for(j=i+1;j<n;j++)
        {
            if(a[minps]>a[j])
            {
                minps=j;
            }
            
        }
        temp=a[minps];
        a[minps]=a[i];
        a[i]=temp;
    }
    printf("array after sorted :  ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void main()
{
    int n,i;
    printf("enter the size of the array ");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements in the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
}
