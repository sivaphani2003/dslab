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
            if (temp->data==ele)
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
        for(temp=first;temp->right!=NULL;temp=temp->right)
        {
            for(temp1=temp->right;temp1!=NULL;temp1=temp1->right)
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
    node *temp=first,*temp1;
    int flag=0;
    if (first==NULL)
    {
        printf("NO elements to delete\n");
    }
    else
    {
        if (first->data==x)
        {
            first=first->right;
            free(temp);
        }
        else
        {
            temp1=first->right;
            while(temp!=NULL)
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
node* insertatbegin(node *first,int x)
{
    node *new,*temp;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->right=NULL;
    new->left=NULL;
    if (first==NULL)
    {
        first=new;
    }
    else
    {
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
    }
    else
    {
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=new;
        new->left=temp;
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
    int x;
    node *temp=NULL,*temp1=first;
    if (first==NULL)
    {
        return temp;
    }
    else
    {
        while(temp1!=NULL)
        {
            temp=insertatbegin(temp,temp1->data);
            temp1=temp1->right;
        }
    }
    return temp;
}
int main()
{
    int x,c,ele,xl,xi,pos,xd,ch;
    node *head=NULL;
    node *iob,*ioe,*in;
    printf("Enter your choice\n1:create\n2:display\n3:count\n4:search\n5:insert at beginning\n6:insert at ending\n7:insert at position\n8:delete\n9:sort\n10:reverse\n11:exit\n");
    scanf("%d",&ch);
    while(ch!=11)
    {
        switch(ch)
        {
            case 1: head=create(head);
                    break;
            case 2: display(head);
                    break;
            case 3: c=count(head);
                    printf("%d elements in list\n",c);
                    break;
            case 4: printf("Enter element to search:");
                    scanf("%d",&ele);
                    search(head,ele);
                    break;
            case 5: printf("Enter element to insert at beginning:");
                    scanf("%d",&x);
                    head=insertatbegin(head,x);
                    display(head);
                    break;
            case 6: printf("Enter element to insert at ending:");
                    scanf("%d",&xl);
                    head=insertatend(head,xl);
                    display(head);
                    break;
            case 7: printf("Enter position to insert an element:");
                    scanf("%d",&pos);
                    printf("Enter element to insert at position:");
                    scanf("%d",&xi);
                    head=insertatpos(head,xi,pos);
                    display(head);
                    break;
            case 8: printf("Enter element to delete:");
                    scanf("%d",&xd);
                    delete(head,xd);
                    display(head);
                    break;
            case 9: head=sort(head);
                    display(head);
                    break;
            case 10:head=reverse(head);
                    display(head);
                    break;
            default:printf("Enter a correct choice\n");
                    break;
        }
        printf("Enter your choice\n1:create\n2:display\n3:count\n4:search\n5:insert at beginning\n6:insert at ending\n7:insert at position\n8:delete\n9:sort\n10:reverse\n11:exit\n");
        scanf("%d",&ch);
    }
    if (ch==11)
    {
        printf("You entered 11 so exitting program\n");
    }
    return 0;
}
