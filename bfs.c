#include <stdio.h>
#define max 20
int q[20],f=-1,r=-1;
int visited[max],a[10][10],n;
void enque(int x)
{
    if(f==-1)
    {
        f=r=0;
    }
    else
    {
        ++r;
    }
    q[r]=x;
}
int deque()
{
    if(f==-1)
    {
        return -1;
    }
    else
    {
        int x=q[f];
        if(f==r)
        {
            f=r=-1;
        }
        else
        {
            ++f;
        }
        return x;
    }
}
void bfs(int v)
{
    int i;
    int u=v;
    visited[u]=1;
    printf("%d ",v);
    while(1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[u][i]==1&& visited[i]==0)
            {
                enque(i);
                visited[i]=1;
                printf("%d ",i);
            }
        }
        if(f==-1)
        return;
        else
        u=deque();
    }
}
int main()
{
    int v;
    printf("enter the size of the augmented matrix: ");
    scanf("%d",&n);
    printf("\n enter the elements in the matrix: \n");
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the v value\n");
    scanf("%d",&v);
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    bfs(v);
    return 0;
}
