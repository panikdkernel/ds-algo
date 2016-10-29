#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL,*end=NULL,*start2=NULL,*end2=NULL;
int sizeoflist;


struct node* createNode(void);
void display(struct node*);
void delete_n(int n);
void concatenate();
void copy();
void reverse();
void split(int n);
int main(int argc, char const *argv[])
{
	int choice,i,n,count;
	struct node *temp, *temp1,*temp2;
	while(1)
	{
		printf("*****************  MENU  *******************\n");
		printf("1. Create list\n");
		printf("2. Display linked list\n");
		printf("3. Add a node at nth position\n");
		printf("4. Delete a element from linked list\n");
		printf("5. Add a node at the begining of the list\n");
		printf("6. copy to another list\n");
		printf("7. concatenate two lists\n");
		printf("8. Size of the linked list\n");
		printf("9. reverse linked list\n");
		printf("10.split the list\n");
		printf("0. Quit\n");
		printf("********************************************\n\n");

		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&choice);

		if(choice==0)
		{
			printf("EXITING PROGRAM .................\n");
			break;
		}

		switch(choice)
		{
			case 1:	printf("ENTER SIZE OF THE LIST: ");
					scanf("%d",&sizeoflist);
					for(i=0;i<sizeoflist;i++)
					{
						temp=createNode();
    					temp->next = NULL;
    					if(start == NULL)
    					{
        					start = temp;
        					end = temp;
   						}
    					else
    					{
        					end->next = temp;
        					end = end->next;
    					}
						display(start);
					}
				break;

			case 2:display(start);
				break;

			case 3:printf("Enter the position where the node has to be created\n");
                   scanf("%d",&n);
                   temp=start;
                   for(i=0;i<n-1 && temp!=NULL;i++)
                   {
                       temp=temp->next;
                   }
                   if(temp==NULL)
                   {
                       printf("out of bounds\n");
                       break;
                   }
                   else
                   {
                       temp1=createNode();
                       if(temp==start)
                       {
                           temp1->next=start;
                           start=temp1;
                       }
                       else
                       {temp1->next=temp->next;
                       temp->next=temp1;
                       }
                   }
                   display(start);
				break;

			case 4:printf("Enter the element to be deleted\n");
                   scanf("%d",&n);
                   delete_n(n);
                   display(start);
                   
				break;

			case 5:temp=createNode();
					temp->next=start;
					start=temp;
					display(start);

				break;

			case 6:copy();
				break;

			case 7:concatenate();
				break;

			case 8:
				   count = 0;
    			   temp = start;
    			   while(temp != NULL)
    			   {
        		   count++;
        		   temp = temp->next;
    			   }
    			   printf("SIZE OF THE LIST : %d\n",count);
				break;

			case 9:reverse();
				   display(start);	
				break;

			case 10:
                printf("Enter position after which the list splits\n");
                scanf("%d", &n);
                getchar();
                split(n);			
				break;		

			default : printf("INVALID CHOICE. TRY AGAIN\n");
				break;
		}


	}
	return 0;
}
//inserts a node at the end of the list
struct node* createNode(void)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("ENTER DATA: ");
	scanf("%d",&temp->data);
	return temp;
}
// displays entire list
void display(struct node *start)
{	struct node *temp;
	if(start==NULL)
	{
		printf("EMPTY LIST\n");
		return;
	}
	temp=start;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void delete_n(int n)
{
	struct node *temp, *prev;
	temp = start;
	while(temp != NULL)
	{
		if(temp->data == n)
		{
			if(temp == start)
			{
				start = temp->next;
				prev = temp = start;
			}
			else
			{
				prev->next = temp->next;
				prev = prev->next;
				temp = prev->next;
			}
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}

	}
}

void copy(){
    if(start == NULL)
        return;
    struct node *ptr = start;
    struct node *ptr2 = start2;
    struct node * temp;
    while(ptr != NULL){
        temp =(struct node *)malloc(sizeof(struct node));
        temp->data = ptr->data;
        temp->next = NULL;
        if(ptr == start)
            start2 = ptr2 = temp;
        else{
            ptr2->next = temp;
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    end2 = ptr2;

    printf("Copied linked list\n");

    display(start2);
      
}


void concatenate(void){
    printf("Concatenated\n");
    display(start);
    printf("and\n");
    display(start2);
    end->next = start2;
}

void reverse(){
	struct node *current = start;
	struct node *prev = NULL, *node_next = NULL;
	while(current != NULL){
			node_next = current->next;
			current->next = prev;
			prev = current;
			current = node_next;

	}
	start = prev;
}

void split(int n){
    int i; 
    struct node * ptr = start;
    if(ptr == NULL)
        return;
    for(i = 0; i < n && ptr != NULL; i++)
        ptr = ptr->next;
    if(ptr == NULL){
        printf("out of bounds\n");
        return;
    }
    start2 = ptr->next;
    ptr->next = NULL;
    end2 = end;
    end = ptr;

    printf("part1\n");
    display(start);
    printf("part2\n");
    display(start2);

}