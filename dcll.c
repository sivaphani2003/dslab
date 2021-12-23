
#include <stdio.h>
#include <stdlib.h>
struct dcll
{
    int data;
    struct dcll *right;
    struct dcll *left;
};
typedef struct dcll node;
node* create(node* first)
{
    int x;
    node *temp=first,*new;
    printf("Enter data\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->right=NULL;
        new->left=NULL;
        if(first==NULL)
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
        printf("Enter data (enter -1 to stop)\n");
        scanf("%d",&x);
    }
    temp->right=first;
    first->left=temp;
    return first;
}
void display(node *first)
{
    node *temp=first;
    if (first==NULL)
    {
        printf("No list to print\n");
    }
    else
    {
        printf("|%d|",temp->left->data);
        do
        {
            printf("<--|%d|-->",temp->data);
            temp=temp->right;
        }while(temp!=first);
        printf("|%d|",temp->data);
    }
}

int main()
{
    node *head=NULL;
    head=create(head);
    display(head);
    return 0;
}


