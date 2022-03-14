#include<stdio.h>
void Adjust(int a[],int i,int n)
{
    int j, item;
    j = 2*i;
    item = a[i];
    while (j <= n)
    {
        if ((j < n) && (a[j] < a[j+1]))
            j = j + 1;
        if (item >= a[j])
            break;
        a[ j/2 ] = a[j]; j = 2*j;
    }
    a[ j/2 ] = item;
}
void Heapify(int a[], int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
        Adjust(a,i,n);
}
void Heapsort(int a[], int n)
{
    int i, t;
    Heapify(a,n);
    for( i = n; i > 1; i--)
    {
        t = a[i];
        a[i] = a[1];
        a[1] = t;
        Adjust(a, 1, i-1);
    }
}
void main()
{
    int i, n, a[25];
    printf("\nEnter size of Heap:");
    scanf("%d",&n);
    printf("\nEnter elements of heap:");
    for(i = 1; i<= n; i++)
        scanf("%d",&a[i]);
    Heapsort(a,n);
    printf("\n Sorted Array: \n");
    for(i = 1; i<= n; i++)
        printf("%d ",a[i]);
}
