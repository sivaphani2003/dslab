#include <stdio.h>
#define max 20
int visited[max],a[10][10],n;
void dfs(int v)
{
    printf("%d ",v);
    visited[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[v][i]==1&& visited[i]==0)
        {
            dfs(i);
        }
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
        visited[i]=0;
    }
    printf("enter the v value\n");
    scanf("%d",&v);
    dfs(v);
    return 0;
}
