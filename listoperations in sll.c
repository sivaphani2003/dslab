#include<stdio.h>
#include<stdlib.h>
struct list1
{
        int data;
        struct list1 *next;
};
typedef struct list1 node;
node* addnode(node* first,node *new)
{
        node *temp=first;
        if (first==NULL)
        {
                first=new;
        }
        else
        {
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=new;
        }
        return first;
}
void sort(node *first)
{
        node *temp1,*temp2,*new;
        new=(node*)malloc(sizeof(node));
        new->data=0;
        new->next=NULL;
        for(temp1=first;temp1->next!=NULL;temp1=temp1->next)
        {
                for(temp2->next=first;temp2!=NULL;temp2=temp2->next)
                {
                        if(temp1->data > temp2->data)
                        {
                                new->data = temp1->data;
                                temp1->data = temp2->data;
                                temp2->data=new->data;
                        }
                }
        }
}
node* create(node *first)
{
        node *new,*prev;
        int x;
        printf("Enter the data value(enter -1 to stop)\n");
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
                printf("enter data (enter -1 to stop)\t");
                scanf("%d",&x);
        }
        return first;
}
void display(node *first)
{
        node *temp=first;
        if(first==NULL)
        {
                printf("No list to print");
        }
        else
        {
                while(temp!=NULL)
                {
                        printf("|%d|->",temp->data);
                        temp=temp->next;
                }
                printf("NULL\n");
        }
}
node * concatenate(node* l1,node *l2)
{
        node *l3=NULL;
        node *temp;
        if(l1==NULL)
        {
                l3=l2;
        }
        else if (l2==NULL)
        {
                l3=l1;
        }
        else
        {
                node *new;
                temp=l1;
                while(temp!=NULL)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=temp->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        temp=temp->next;
                }
                temp=l3;
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=l2;
          
       }
      return l3;
}
node * listunion(node *l1,node *l2)
{
        node *l3=NULL,*new;
        while(l1!=NULL && l2!=NULL)
        {
                if(l1->data<l2->data)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l1->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l1=l1->next;
                }
                else if(l2->data<l1->data)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l2->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l2=l2->next;
                }
                else
                {
                   new=(node*)malloc(sizeof(node));
                        new->data=l1->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l1=l1->next;
                        l2=l2->next;
                }
        }
        if(l1==NULL)
        {
                while(l2!=NULL)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l2->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l2=l2->next;
                }
        }
        if(l2==NULL)
        {
                while(l1!=NULL)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l1->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l1=l1->next;
                }
        }
        return l3;
}
node * listmerge(node *l1,node *l2)
{
        node *l3=NULL,*new;
        while(l1!=NULL && l2!=NULL)
        {
                if(l1->data<l2->data)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l1->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l1=l1->next;
                }
                else if(l2->data<l1->data)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l2->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l2=l2->next;
                }
                else
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l1->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l3=addnode(l3,new);
                        l1=l1->next;
                        l2=l2->next;
                }
        }
        if(l1==NULL)
        {
                while(l2!=NULL)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l2->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l2=l2->next;
                }
        }
        if(l2==NULL)
        {
                while(l1!=NULL)
                {
                        new=(node*)malloc(sizeof(node));
                        new->data=l1->data;
                        new->next=NULL;
                        l3=addnode(l3,new);
                        l1=l1->next;
                }
        }
        return l3;
}
void main()
{
        node *l1,*l2,*l3,*head=NULL;
        l1=create(head);
        l2=create(head);
        display(l1);
        display(l2);
        l3=concatenate(l1,l2);
        display(l3);
}
