#include <stdio.h>
#include <stdlib.h>
struct dcll 
{
    int data;
    struct dcll *left,*right;
};
typedef struct dcll node;
node* create(node *first)
{
    node *temp,*new;
    int x;
    printf("Enter data and enter -1 to stop\n");
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
        printf("No list to display\n");
    }
    else
    {
        
        do
        {
            printf("<--|%d|-->",temp->data);
            temp=temp->right;
        }while(temp!=first);
        printf("\n");
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
        do
        {
            c++;
            temp=temp->right;
        }while(temp!=first);
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
        do
        {
            if (temp->data==ele)
            {
                flag=1;
                break;
            }
            else
            {
                temp=temp->right;
            }
        }while(temp!=first);
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
node* sort(node *first)
{
    int x;
    node *temp=first,*temp1;
    if(first==NULL)
    {
        printf("No elements to sort\n");
    }
    else
    {
        for(temp=first;temp->right!=first;temp=temp->right)
        {
            for(temp1=temp->right;temp1!=first;temp1=temp1->right)
            {
                if(temp->data>temp1->data)
                {
                    x=temp1->data;
                    temp1->data=temp->data;
                    temp->data=x;
                }
            }
        }
    }
    return first;
}
node *delete(node *first,int x)
{
    node *temp=first,*temp1,*temp2=first;
    int flag=0;
    if (first==NULL)
    {
        printf("No elements to delete\n");
    }
    else
    {
        while(temp2->right!=first)
        {
            temp2=temp2->right;
        }
        if (first->data==x)
        {
            first=first->right;
            free(temp);
            temp2->right=first;
            first->left=temp2;
        }
        else
        {
            temp1=first->right;
            while(temp->right!=first)
            {
                if (temp->data==x)
                {
                    flag=1;
                    break;
                }
                else
                {
                    temp1=temp;
                    temp=temp->right;
                }
            }
            if(flag)
            {
                temp1->right=temp->right;
                temp->right->left=temp1;
                free(temp);
            }
            else
            {
                printf("Element not found to delete\n");
            } 
        }
    }
    return first;
}
node* insertatbeg(node *first,int x)
{
    node *new,*temp=first;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->right=NULL;
    new->left=NULL;
    if (first==NULL)
    {
        first=new;
        first->right=new;
        first->left=new;
    }
    else
    {
        while(temp->right!=first)
        {
            temp=temp->right;
        }
        temp->right=new;
        new->left=temp;
        new->right=first;
        first->left=new;
        first=new;
        
    }
    return first;
}
node* insertatend(node *first,int x)
{
    node *new,*temp=first;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->right=NULL;
    new->left=NULL;
    if(first==NULL)
    {
        first=new;
        first->right=new;
        first->left=new;
    }
    else
    {
        while(temp->right!=first)
        {
            temp=temp->right;
        }
        temp->right=new;
        new->left=temp;
        new->right=first;
        first->left=new;
    }
    return first;
}
node* insertatpos(node *first,int x,int pos)
{
    int i;
    node *temp=first;
    int n=count(first);
    if (pos>1&&pos<n)
    {
        node *new=(node*)malloc(sizeof(node));
        new->data=x;
        new->right=NULL;
        new->left=NULL;
        for (i=1;i<pos-1;i++)
        {
            temp=temp->right;
        }
        new->right=temp->right;
        temp->right=new;
    }
    return first;
}
node* reverse(node *first)
{
    node *present=first;
    node *l3=NULL;
    if(first==NULL)
    {
        return l3;
    }
    do
    {
        l3=insertatbeg(l3,present->data);
        present=present->right;
    } while (present!=first);

    return l3;
}
int main()
{
    int c,ele,x,ch,pos;
    node *head=NULL;
    while(1)
    {
        printf("\nenter your choice");
        printf("\n1.create \n2.display \n3.count \n4.search\n5.insert at beginning \n");
        printf("6.insertion at ending\n7.insertion at given position\n8.delete\n9.sort\n10.reverse\n11.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=create(head);
                    break;
            case 2: display(head);
                    break;
            case 3: c=count(head);
                    printf("there is %d elements present in the doubly circular linked list",c);
                    break;
            case 4: printf("enter a value to search\n");
                    scanf("%d",&x);
                    search(head,x);
                    break;
            case 5: printf("enter a value to insertatbeg\n");
                    scanf("%d",&x);
                    head=insertatbeg(head,x);
                    break;
            case 6: printf("enter a value to insertatend\n");
                    scanf("%d",&x);
                    head=insertatend(head,x);
                    break;
            case 7: printf("enter the element and the position \n");
                    scanf("%d%d",&pos,&x);
                    head=insertatpos(head,pos,x);
                    break;
            case 8: printf("enter thre element to be deleted\n");
                    scanf("%d",&x);
                    head=delete(head,x);
                    break;
            case 9: sort(head);
                    break;
            case 10:head=reverse(head);
                    break;
            case 11:exit(0);
                    break;
            default:printf("please check your given choice");
                    break;
        }
    }
}
