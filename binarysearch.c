#include <stdio.h>
int binarysearch(int a[20],int low,int high,int x)
{
    int mid;
    if(low<=high)
    {
        mid=(high+low)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        else if(a[low]==x)
        {
            return low;
        }
        else if(a[high]==x)
        {
            return high;
        }
        else if(x<a[mid])
        {
            return binarysearch(a,low,mid-1,x);
        }
        else
        {
            return binarysearch(a,mid+1,high,x);
        }
    }
    return -1;
}
int main()
{
    int i,n,ele,x;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements\n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to search\n");
    scanf("%d",&ele);
    x=binarysearch(a,0,n-1,ele);
    if(x==-1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Elemet found\n");
    }
    return 0;
}
