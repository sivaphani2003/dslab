#include<stdio.h>
#include<stdlib.h>
struct AVL
{
    int data;
    struct AVL *left,*right;
};
typedef struct AVL node;
node *single_LL(node *p)
{
    node *q=p->left;
    p->left=q->right;
    q->right=p;
    return q;
}
node *single_RR(node *p)
{
    node *q=p->right;
    p->right=q->left;
    q->left=p;
    return q;
}
node *double_LR(node *p)
{
    p->left=single_RR(p->left);
    p=single_LL(p);
    return p;
}
node *double_RL(node *p)
{
    p->right=single_LL(p->right);
    p=single_RR(p);
    return p;
}
void preorder(node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height(node *p)
{
    if(p==NULL)
    {
        return -1;
    }
    else
    {
        return max(height(p->left),height(p->right))+1;
    }
}
node *insert(node *p,int x)
{
    if(p==NULL)
    {
        p=(node *)malloc(sizeof(node));
        p->data=x;
    }
    else if(x<=p->data)
    {
        p->left=insert(p->left,x);
        if(abs(height(p->left)-height(p->right))==2)
        {
            if(p->left->data>x)
            {
                p=single_LL(p);
            }
            else
            {
                p=double_LR(p);
            }
            
        }
    }
    else if(x>p->data)
    {
        p->right=insert(p->right,x);
        if(abs(height(p->left)-height(p->right))==2)
        {
            if(p->right->data<x)
            {
                p=single_RR(p);
            }
            else
            {
                p=double_RL(p);
            }
        }
    }
    return p;
}
void main()
{
    node *p=NULL;
    int x,ch;
    printf("1.Insert\n2.Preorder\n3.Postorder\n4.Exit\n");
    while(1)
    {
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter a value to insert\n");
                   scanf("%d",&x);
                   p=insert(p,x);
                   break;
            case 2:printf("AVL tree display in Preorder :\n");
                   preorder(p);
                   printf("\n");
                   break;
            case 3:printf("AVL tree display in postorder :\n");
                   postorder(p);
                   printf("\n");
                   break;
            case 4:printf("While loop is terminated\n");
                   exit(0);
            default:printf("Check your choice\n");
        }
    }
}
