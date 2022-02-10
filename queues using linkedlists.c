#include <stdio.h>
#include <stdlib.h>
struct queue
{
        int data;
        struct queue *next;
};
typedef struct queue node;
node *rear=NULL;
node *front=NULL;
void enqueue(int x)
{
        node *new;
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(front==NULL)
        {
                front=rear=new;
        }
        else
        {
                rear->next=new;
                rear=new;
        }
}
int dequeue()
{
        int x;
        node *temp=front;
        if (front==NULL)
        {
                return -1;
        }
        else
        {
                x=front->data;
                if(front==rear)
                {
                    front=rear=NULL;
                }
                else
                {
                    front=front->next;
                    free(temp);
                }
                
                return x;
        }
}
void display()
{
        node *temp;
        temp=front;
        printf("The elements in the list are: \n");
        if(front==NULL)
        {
            printf("There are no elements in the queue\n");
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
int main()
{
        int ch,x;
        printf("Enter choice\n1:insert\n2:delete\n3:Display\n4:Exit\n");
        scanf("%d",&ch);
        while(ch!=4)
        {
                switch(ch)
                {
                        case 1:printf("Enter value to insert\n");
                               scanf("%d",&x);
                               enqueue(x);
                               break;
                        case 2:x=dequeue();
                               printf("Element removed from front is %d\n",x);
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
