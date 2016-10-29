#include <stdio.h>
#define max 5

int st[max];
int top = -1;

int push(int);
void pop(void);
int peek(void);
void display(void);


int main()
{
    int option,val;
    do{
        printf("\n ******MENU*******");
        printf("\n 1. push");
        printf("\n 2. pop ");
        printf("\n 3. peek");
        printf("\n 4. display");
        printf("\n 5. exit");
        printf("\n Enter the your choice ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                {
                    printf("\n Enter the element : ");
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
                    printf("\n STACK STATUS :top element is %d",val);
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

int push(int val)
{
    if(top == max-1)
    {
        printf("\nSTACK STATUS : Overflow");
        return 0;
    }
    top++;
    st[top] = val;
    return top;
}

void pop(void)
{
    if(top == -1)
    {
        printf("\n STACK STATUS :UNDERFLOW");
        return;
    }
    int val = st[top];
    top--;
    printf("\n STACK STATUS :element deleted  %d",val);
    return;
}

int peek(void)
{
    if(top == -1)
    {
        printf("\n STACK STATUS :Stack is Empty");
        return 0;
    }
    return (st[top]);
}

void display(void)
{
    if(top == -1)
    {
        printf("\n STACK STATUS :Stack is Empty");
        return;
    }
    
    for(int i = top;i>=0;i--)
    {
        printf("\n %d",st[i]);
    }
    return;
}
