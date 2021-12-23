
#include <stdio.h>
#include <stdlib.h>
struct dll 
{
    int data;
    struct dll *left,*right;
};
typedef struct dll node;
node* create(node *first)
{
    node *temp,*new;;
    int x;
    printf("Enter data\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->left=NULL;
        new->right=NULL;
        if (first==NULL)
        {
            first=new;
            temp=new;
        }
        else
        {
            temp->right=new;
            new->left=temp;
            temp=new;
        }
        printf("Enter data (Enter -1 to stop)\n");
        scanf("%d",&x);
    }
    return first;
}
void display(node *first)
{
    node *temp=first;
    if (first==NULL)
    {
        printf("No list to display\n");
    }
    else
    {
        printf("NULL");
        while(temp!=NULL)
        {
            printf("<--|%d|-->",temp->data);
            temp=temp->right;
        }
        printf("NULL\n");
    }
}
int count(node *first)
{
    node *temp=first;
    int c=0;
    if (first==NULL)
    {
        return c;
    }
    else
    {
        while(temp!=NULL)
        {
            c++;
            temp=temp->right;
        }
    }
    return c;
}
void search(node *first,int ele)
{
    node *temp=first;
    int flag=0;
    if (first==NULL)
    {
        printf("No list to search\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if (temp->data=ele)
            {
                flag=1;
                break;
            }
            else
            {
                temp=temp->right;
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
}
int main()
{
    int c,ele;
    node *head=NULL;
    head=create(head);
    display(head);
    c=count(head);
    printf("Number of elements in double linked list are %d\n",c);
    printf("Enter element to search\n");
    scanf("%d",&ele);
    search(head,ele);
    return 0;
}


