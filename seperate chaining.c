#include <stdio.h>
#include <stdlib.h>
struct hashtable
{
    int data;
    struct hashtable *next;
};
typedef struct hashtable node;
int hash(int x)
{
    return x%10;
}
void insert(node *t[10],int x)
{
    int i=hash(x);
    node *p=(node*)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    if(t[i]->next==NULL)
    {
        t[i]->next=p;
    }
    else
    {
        p->next=t[i]->next;
        t[i]->next=p;
    }
}
void search(node *t[10],int x)
{
    int i=hash(x),flag=0;
    node *p=t[i]->next;
    if(p==NULL)
    {
        flag=0;
    }
    else
    {
        while(p!=NULL)
        {
            if (p->data==x)
            {
                flag=1;
                break;
            }
            else
            {
                p=p->next;
            }
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
void delete(node *t[10],int x)
{
    int i=hash(x),flag=0;
    node *p=t[i]->next,*p1=t[i];
    if (p==NULL)
    {
        printf("No elements present to delete\n");
    }
    else
    {
        while(p!=NULL)
        {
            if(p->data==x)
            {
                flag=1;
                break;
            }
            else
            {
                p1=p;
                p=p->next;
            }
        }
        if (flag)
        {
            p1->next=p->next;
            free(p);
        }
        else
        {
            printf("Element not present to delete\n");
        }
    }
}
void display(node *t[10])
{
    int i;
    for (i=0;i<10;i++)
    {
        node *p=t[i]->next;
        if (p==NULL)
        {
                printf("NULL\n");
        }
        else
        {
            while(p!=NULL)
            {
                    printf("|%d|->",p->data);
                    p=p->next;
            }
            printf("NULL");
            printf("\n");
        }
    }
}
int main()
{
    node *t[10];
    int i,ch,x1,x2,x3;
    for (i=0;i<10;i++)
    {
        t[i]=(node*)malloc(sizeof(node));
        t[i]->next=NULL;
    }
    while(1)
    {
        printf("1:Insert\n2:Display\n3:Search\n4:Delete\n5:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter value to input\n");
                    scanf("%d",&x1);
                    insert(t,x1);
                    break;
            case 2: display(t);
                    break;
            case 3: printf("Enter element to search\n");
                    scanf("%d",&x2);
                    search(t,x2);
                    break;
            case 4: printf("Enter element to delete\n");
                    scanf("%d",&x3);
                    delete(t,x3);
                    break;
            case 5: exit(0);
            default:printf("Enter a valid choice\n");
                    break;
        }
    }
    return 0;
}
