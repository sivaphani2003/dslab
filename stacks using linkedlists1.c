#include <stdio.h>
#include <stdlib.h>
struct stack
{
        int data;
        struct stack *next;
};
typedef struct stack node;
node *top=NULL;
void push(int x)
{
        node *new;
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(top==NULL)
        {
                top=new;
        }
        else
        {
                new->next=top;
                top=new;
        }
}
int pop()
{
        int x;
        node *temp;
        if (top==NULL)
        {
                return -1;
        }
        else
        {
                x=top->data;
                temp=top;
                top=top->next;
                free(temp);
                return x;
        }
}
void display()
{
        node *temp;
        temp=top;
        printf("The elements in the list are: ");
        while(temp!=NULL)
        {
                printf("%d\n",temp->data);
                temp=temp->next;
        }
}
int main()
{
        int ch,x;
        printf("Enter choice\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
        scanf("%d",&ch);
        while(ch!=4)
        {
                switch(ch)
                {
                        case 1:printf("Enter value to push\n");
                               scanf("%d",&x);
                               push(x);
                               break;
                        case 2:x=pop();
                              if(x==-1)
                              {
                                  printf("the stack is underflowed\n");
                              }
                              else
                              {
                                   printf("the element %d is popped out\n",x);
                              }
                              break;
                        case 3:display();
                               break;
                        case 4:exit(0);
                }
                printf("Enter choice\n");
                scanf("%d",&ch);
        }
        return 0;
}
