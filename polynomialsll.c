#include <stdio.h>
#include <stdlib.h>
struct polynomial
{
        int coeff;
        int exp;
        struct polynomial *next;
};
typedef struct polynomial node;
node* addterm(node *first,node *new)
{
        node *temp,*temp1;
        if (first==NULL)
        {
            first=new;
            temp=new;
        }
        else if(first->exp<new->exp)
        {
            new->next=first;
            first=new;
        }
        else if(first->exp==new->exp)
        {
            first->coeff=first->coeff+new->coeff;
        }
        else
        {
            temp=first->next;
            temp1=first;
            while(temp!=NULL && temp->exp>new->exp)
            {
                temp1=temp;
                temp=temp->next;
            }
            if (temp==NULL)
            {
                temp1->next=new;
            }
            else if (temp->exp==new->exp)
            {
                temp->coeff=temp->coeff+new->coeff;
            }
            else
            {
                temp1->next=new;
                new->next=temp;
            }
        }
        return first;

}
node* create()
{
        node *new,*first=NULL;
        char c;
        do
        {
                new=(node*)malloc(sizeof(node));
                new->next=NULL;
                printf("Enter coeff\n");
                scanf("%d",&new->coeff);
                printf("Enter the exponent\n");
                scanf("%d",&new->exp);
                first=addterm(first,new);
                printf("Enter any term other than 'n' to stop\n");
                scanf(" %c",&c);
        }while(c!='n');
        return first;
}
void display(node *first)
{
        node *temp=first;
        if (temp==NULL)
        {
                printf("No polynomial to display\n");
        }
        else
        {
                while(temp->next!=NULL)
                {
                        printf("%dX^%d+",temp->coeff,temp->exp);
                        temp=temp->next;
                }
                printf("%dX^%d\n",temp->coeff,temp->exp);
        }
}
node *add(node *p1,node *p2)
{
        node *p3=NULL;
        node *new;
        while(p1!=NULL && p2!=NULL)
        {
                new=(node*)malloc(sizeof(node));
                new->next=NULL;
                if (p1->exp>p2->exp)
                {
                        new->coeff=p1->coeff;
                        new->exp=p1->exp;
                        p3=addterm(p3,new);
                        p1=p1->next;
                }
                else if(p1->exp<p2->exp)
                {
                        new->coeff=p2->coeff;
                        new->exp=p2->exp;
                        p3=addterm(p3,new);
                        p2=p2->next;
                }
                else
                {
                        new->coeff=p1->coeff+p2->coeff;
                        new->exp=p1->exp;
                        p3=addterm(p3,new);
                        p1=p1->next;
                        p2=p2->next;
                }
                if (p1==NULL)
                {
                        while(p2!=NULL)
                        {
                                new=(node*)malloc(sizeof(node));
                                new->next=NULL;
                                new->coeff=p2->coeff;
                                new->exp=p2->exp;
                                p3=addterm(p3,new);
                                p2=p2->next;
                        }
                }
                if (p2==NULL)
                {
                        while(p1!=NULL)
                        {
                                new=(node*)malloc(sizeof(node));
                                new->next=NULL;
                                new->coeff=p1->coeff;
                                new->exp=p1->exp;
                                p3=addterm(p3,new);
                                p1=p1->next;
                        }
                }
        }
        return p3;
}
node *sub(node *p1,node *p2)
{
        node *p3=NULL,*new;
        while(p1!=NULL && p2!=NULL)
        {
                new=(node*)malloc(sizeof(node));
                new->next=NULL;
                if (p1->exp>p2->exp)
                {
                        new->coeff=p1->coeff;
                        new->exp=p1->exp;
                        p3=addterm(p3,new);
                        p1=p1->next;
                }
                else if (p1->exp<p2->exp)
                {
                        new->coeff=-p2->coeff;
                        new->exp=p2->exp;
                        p3=addterm(p3,new);
                        p2=p2->next;
                }
                else
                {
                        new->coeff=p1->coeff-p2->coeff;
                        new->exp=p1->exp;
                        p3=addterm(p3,new);
                        p1=p1->next;
                        p2=p2->next;
                }
                if (p1==NULL)
                {
                        while(p2!=NULL)
                        {
                                new=(node*)malloc(sizeof(node));
                                new->next=NULL;
                                new->coeff=-p2->coeff;
                                new->exp=p2->exp;
                                p3=addterm(p3,new);
                                p2=p2->next;
                        }
                }
                if (p2==NULL)
                {
                        while(p1!=NULL)
                        {
                                new=(node*)malloc(sizeof(node));
                                new->next=NULL;
                                new->coeff=p1->coeff;
                                new->exp=p1->exp;
                                p3=addterm(p3,new);
                                p1=p1->next;
                        }
                }
        }
        return p3;
}
node *mul(node *p1, node*p2)
{
        node *p3=NULL,*new,*temp=p2;
        while(p1!=NULL)
        {
                p2=temp;
                while(p2!=NULL)
                {
                        new=(node*)malloc(sizeof(node));
                        new->next=NULL;
                        new->coeff=p1->coeff*p2->coeff;
                        new->exp=p1->exp+p2->exp;
                        p3=addterm(p3,new);
                        p2=p2->next;
                }
                p1=p1->next;
        }
        return p3;
}
int main()
{
        node *p1=NULL,*p2=NULL,*p3,*p4,*p5;
        int ch;
        
        while(1)
        {
            printf("Enter your choice\n");
            printf("1:Create\n2:display\n3:add\n4:sub\n5:multiply\n6:exit\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:printf("enter first polynomial\n");
                       p1=create();
                       printf("enter second polynomial\n");
                       p2=create();
                       break;
                case 2: printf("the first polynomial is : ");
                        display(p1);
                        printf("the second polynomial is : ");
                        display(p2);
                        break;
                case 3:
                       p3=add(p1,p2);
                       printf("the polynomial after addition is\n");
                       display(p3);
                       break;
                case 4:
                       printf("the polynomial after subraction is\n");
                       p4=sub(p1,p2);
                       display(p4);
                       break;
                case 5:
                       printf("the polynomial after multiplication is\n");
                       p5=mul(p1,p2);
                       display(p5);
                       break;
                case 6:exit(0);
                default:printf("Enter a correct choice\n");
                        break;
            }
        }
return 0;
}
