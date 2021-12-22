#include<stdio.h>
#include<stdlib.h>
struct circularlist
{
    int data;
    struct circularlist *next;
};
typedef struct circularlist node;
node* create()
{
    node *first=NULL;
    node *new,*prev;
    int x;
    printf("\nEnter the data value(enter -1 to stop)\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL)
        {
            first=new;
        }
        else{
            prev->next=new;
        }
        prev=new;
        scanf("%d",&x);
    }
    prev->next=first;
    return first;
}
int count(node*first)
{
    node*temp=first;
    int c=0;
    if(first==NULL)
    {
        return c;
    }
    else
    {
        do
        {
            c++;
            temp=temp->next;
        } while (temp!=first);
        
    }
    return c;
}
void search(node *first,int ele)
{
    int flag=0;
    node * temp=first;
    if(first==NULL)
    {
        printf("\nthere is no list to print\n");
    }
    else{
        do
        {
            if(temp->data==ele)
            {
                printf("the %d element is found",ele);
                flag=1;
                break;
            }
            temp=temp->next;
        }while(temp!=first);
        if (flag==0)
        {
            printf("the %d element is not found",ele);
        }
    }
}
node * insertatbeg(node* first,int x)
{
    node *temp=first;
    node* new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(first==NULL)
    {
        first=new;
        new->next=first;
    }
    else
    {
        while(temp->next!=first)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=first;
        first=new;
    }
    return first;
}
node * insertatend(node* first,int x)
{
    node *temp=first;
    node* new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(first==NULL)
    {
        first=new;
        new->next=first;
    }
    else
    {
        while(temp->next!=first)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=first;
    }
    return first;
}
node * insertatpos(node* first,int pos,int x)
{
    int n;
    node *new=(node *)malloc(sizeof(node)),*temp;
    temp=first;
    new->data=x;
    new->next=NULL;
    n=count(first);
    if(pos>0 && pos<n)
    {
        while(pos-2)
        {
            temp=temp->next;
            pos--;
        }
        new->next=temp->next;
        temp->next=new;
    }
    else
    {
        printf("ther is not possible to insert the element at that position");
    }

    return first;
}
node *delete(node *first,int x)
{
    node *temp,*temp1;
    temp=first;
    int flag=0;
    if(first==NULL)
    {
        printf("There is no elements in the list to delete");
    }
    else if(first->data==x)
    {
        temp1=first;
        temp=first;
        while(temp->next!=first)
        {
            temp=temp->next;
        }
        first=first->next;
        temp->next=first;
        free(temp);
    }
    else
    {
        temp1=first;
        temp=temp->next;
        while(temp!=NULL)
        {
            if((temp -> data) == x)
            {
                flag=1;
                break;
            }
            else
            {
                temp1=temp;
                temp=temp->next;
            }
        }
        if(flag==1)
        {
            temp1->next=temp->next;
            free(temp);
        }
        else
        {
            printf("element %d is not found",x);
        }
    }
    return first;
}
void display(node *first)
{
    node *temp=first;
    if(first==NULL)
    {
        printf("\nNo list to print\n");
    }
    else
    {
        do
        {
            printf("|%d|->",temp->data);
            temp=temp->next;
        }while(temp!=first);
    }
}
void main()
{
    int ch,c,x,pos;
    node *head;
    while(1)
    {
        printf("\nenter your choice");
        printf("\n1.create\n2.display \n3.count \n4.search\n5.insert at beginning \n");
        printf("6.insertion at ending\n7.insertion at given position\n8.delete\n9.sort\n10.reverse\n11.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=create();
                    break;
            case 2: display(head);
                    break;
            case 3: c=count(head);
                    printf("there is %d elements present in the circular linked list",c);
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
            case 7: printf("enter the element and the position in order \n");
                    scanf("%d%d",&x,&pos);
                    head=insertatpos(head,pos,x);
                    break;
            case 8: printf("enter the element to be deleted\n");
                    scanf("%d",&x);
                    head=delete(head,x);
                    break;
            // case 9: sort(head);
            //         break;
            // case 10:head=reverse(head);
            //         break;
            case 11:exit(0);
                    break;
            default:printf("please check your given choice");
                    break;
        }
    }
}
