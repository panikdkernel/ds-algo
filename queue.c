#include <stdio.h>
#define SIZE 5

int front=-1,rear=-1;// initial value set to -1 for empty queue


//inserts elements in the array at the front
void insert(int element,int queue[])
{
    if(rear==SIZE-1)
    {
        printf("QUEUE STATUS: OVERFLOW\n\n");
        return;
    }
    rear++;
    queue[rear]=element;
    printf("QUEUE STATUS: ELEMENT %d ENQUEUED\n\n",element);
    if(rear==0)
        front=0;
}

// deletes front elment from the queue
void delete(int queue[])
{   int element;// used to print in the queue status
    if(front==-1)
    {
        printf("QUEUE STATUS: UNDERFLOW\n\n");
        return;
    }
    if(front==rear)//when at the last element, resets the list
    {
        front=-1;
        rear=-1;
        return;
    }
    element=queue[front];
    front++;//point to next element in the queue
    printf("QUEUE STATUS: ELEMENT %d DEQUEUED\n\n",element);
    
}


void display(int queue[])
{
    if(front==-1 && rear==-1)
    {
        printf("QUEUE STATUS: EMPTY QUEUE\n\n");
        return;
    }
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n\n");    
}


int main()
{
    int queue[SIZE];
    int choice;
    int element;
    while(1)
    {
        printf("#################  MENU  ################\n");
        printf("1. INSERT ELEMENT\n");
        printf("2. DELETE ELEMENT\n");
        printf("3. DISPLAY QUEUE\n");
        printf("4. PEEK\n");
        printf("0. EXIT\n");
        printf("#########################################\n\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        if(choice==0)
            break;
        switch(choice)
        {
            case 1 :printf("\nENTER A NUMBER: ");
                    scanf("%d",&element);
                    insert(element,queue);//inserts the element in the queue
                break;
                
            case 2 :delete(queue);
                break;
                
            case 3 :display(queue);
                break;
                
            case 4 :if(front==-1) printf("QUEUE STATUS: EMPTY QUEUE\n\n");
                    else printf("QUEUE STATUS: ELEMENT IN FRONT IS %d\n\n",queue[front]);
                break;
                
            default:printf("INVALID CHOICE\n");    
        }
    }
}

