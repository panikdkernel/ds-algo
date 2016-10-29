#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct node*front=NULL,*rear=NULL;
void enqueue(int element)
{
    struct node* temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=element;
    if(front==NULL || element<front->data)
    {
        temp->next=front;
        front=temp;
    }
    else
    {
    ptr=front;
    while(ptr->next!=NULL && ptr->next->data <= element)
        ptr=ptr->next;
    temp->next=ptr->next;
    ptr->next=temp;
    }
}
int dequeue(void)
{   
    if(front!=NULL)
    {
        struct node* temp;
        int ele;
        ele=front->data;
        temp=front;
        front=front->next;
        free(temp);
        return ele;
    }
    printf("empty queue\n");
    return -1;
    
}
void display(void);
struct node* createNode(void);
int main()
{
    int choice;
    int element,size,i;
    struct node*temp;
    while(1)
    {
        printf("#################  MENU  ################\n");
        printf("1. ENQUEUE ELEMENT\n");
        printf("2. DEQUEUE\n");
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
                    enqueue(element);//inserts the element in the queue
                break;
                
            case 2 :element=dequeue();
                    if(element==-1)
                    {
                        printf("empty queue\n");
                    }
                    else
                    {
                        printf(" ELEMENT %d dequeued\n",element);
                    }
                break;
                
            case 3 :display();
                break;
                
            case 4 :if(front==NULL) printf("QUEUE STATUS: EMPTY QUEUE\n\n");
                    else printf("QUEUE STATUS: ELEMENT IN FRONT IS %d\n\n",front->data);
                break;
                
            default:printf("INVALID CHOICE\n");    
        }
    }
}

struct node* createNode(void)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("ENTER DATA: ");
	scanf("%d",&temp->data);
	return temp;
}
// displays entire list
void display(void)
{	struct node *temp;
	if(front==NULL)
	{
		printf("EMPTY LIST\n");
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}