#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct BST
{
    int data;
    struct BST *left,*right;
};
typedef struct BST node;
node* insert(node *p,int x)
{
    node *new;
    if (p==NULL)
    {
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->left=new->right=NULL;
        p=new;
    }
    else
    {
        if (p->data>x)
        {
            p->left=insert(p->left,x);
        }
        else
        {
            p->right=insert(p->right,x);
        }
    }
    return p;
}

void inorder(node *p)
{
    if (p!=NULL)
    {
        inorder(p->left);
        printf("%d\t",p->data);
        inorder(p->right);
    }
}

void preorder(node *p)
{
    if (p!=NULL)
    {
        printf("%d\t",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p)
{
    if (p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\t",p->data);
    }
}

node* findmin(node *p)
{
    if (p!=NULL)
    {
        while(p->left!=NULL)
        {
            p=p->left;
        }
    }
    return p;
}

node* findmax(node *p)
{
    if (p!=NULL)
    {
        while(p->right!=NULL)
        {
            p=p->right;
        }
    }
    return p;
}

void search(node *p,int x)
{
    int flag=0;
    if (p!=NULL)
    {
        while(p!=NULL)
        {
            if (p->data>x)
            {
                p=p->left;
            }
            else if (p->data<x)
            {
                p=p->right;
            }
            else
            {
                flag=1;
                break;
            }
        }
    }
    if (flag==1)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}
node* delete(node *p,int x)
{
    node *temp;
    if (p==NULL)
    {
        return p;
    }
    else if(x<p->data)
    {
        p->left=delete(p->left,x);
    }
    else if (x>p->data)
    {
        p->right=delete(p->right,x);
    }
    else if (p->left!=NULL && p->right!=NULL)
    {
        x=p->data=findmin(p->right)->data;
        p->right=delete(p->right,x);
    }
    else
    {
        temp=p;
        if (p->right==NULL)
        {
            p=p->left;
        }
        else if(p->left==NULL)
        {
            p=p->left;
        }
        free(temp);
    }
    return p;
}

int main()
{
    node *root=NULL,*min,*max;
    int x,c;
    printf("Enter your choice\n");
    printf("1:Insert\n2:Inorder\n3:Preorder\n4:Postorder\n5:Find min\n6:Find max\n7:Search\n8:Delete\n9:Exit\n");
    scanf("%d",&c);
    while(c!=9)
    {
        switch(c)
        {
            case 1: printf("Enter element to insert\n");
                    scanf("%d",&x);
                    root=insert(root,x);
                    break;
            case 2: printf("Inorder of tree is\n");
                    inorder(root);
                    printf("\n");
                    break;
            case 3: printf("Preorder of tree is\n");
                    preorder(root);
                    printf("\n");
                    break;
            case 4: printf("Postorder of tree is\n");
                    postorder(root);
                    printf("\n");
                    break;
            case 5: min=findmin(root);
                    printf("Minimum element in tree is %d\n",min->data);
                    break;
            case 6: max=findmax(root);
                    printf("Maximum element in tree is %d\n",max->data);
                    break;
            case 7: printf("Enter element to search\n");
                    scanf("%d",&x);
                    search(root,x);
                    break;
            case 8: printf("Enter element to delete\n");
                    scanf("%d",&x);
                    root=delete(root,x);
                    inorder(root);
                    printf("\n");
                    break;
            case 9: exit(0);
            default:printf("Enter correct choice\n");
        }
        printf("Enter your choice\n");
        scanf("%d",&c);
    }
    return 0;
}
