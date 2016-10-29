#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node * create_node()
{
    return((struct node *)malloc(sizeof(struct node)));
}

void push(int val)
{
    struct node *temp;
    temp = create_node();
    temp->data = val;
    if(top == NULL)
    {    
        temp->next = NULL;
        printf("\n STACK STATUS : STACK CREATED \n");
    }    
    else
    {    
        temp->next = top;
        printf("\n STACK STATUS : %d added to stack",val);
    }
    top = temp;
}

void pop(void)
{
    struct node *ptr = top;
    if(top == NULL)
    {
        printf("\n STACK STATUS : UNDERFLOW \n");
        return;
    }
    else
    {
        top = top -> next;
        printf("\n STACK STATUS : deleted value  %d",ptr->data);
        free(ptr);
    }
    return;
}

int peek(void)
{
    if(top == NULL)
    {
        printf("\n STACK STATUS :stack is empty\n");
        return 0;
    }
    return (top->data);
}

void display(void)
{
    struct node *ptr;
    if(top == NULL)
    {
        printf("\nSTACK STATUS :Stack is empty\n");
        return;
    }
    else 
    {
        ptr = top;
        while(ptr!=NULL)
        {
            printf("\n %d",ptr->data);
            ptr = ptr->next; 
        }    
    }
}

int main()
{
    int val,option;
    do{
        printf("\n ******MENU*******");
        printf("\n 1. push");
        printf("\n 2. pop ");
        printf("\n 3. peek");
        printf("\n 4. display");
        printf("\n 5. exit");
        printf("\nEnter your choice : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: 
                {
                    printf("Enter the value to be inserted : ");
                    scanf("%d",&val);
                    push(val);
                }
                break;
            case 2:
                {
                    pop();
                }
                break;
            case 3:
                {
                    val = peek();
                    printf("\nvalue at top is : %d",val);
                }
                break;
            case 4:
                {
                    display();
                }
                break;
        }
        
    }while(option != 5);
}

