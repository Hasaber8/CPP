#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Stack{
    int top;
    int *data;
};


void push(stack*,int item){
    if(stack->top==9){
        printf("Stack Overflow");
        return;
    }
    stack->top++;
    stack->data[stack->top]=item;
}

int pop(stack*){
    int item=0;
    if(stack->top==-1){
        printf("Stack Underflow");
        return 0;
    }
    item =stack->data[stack->top];
    stack->data[stack->top]='\0';
    stack->top--;
    return item;
}

void peek(stack*){
    int t=stack->top;
    printf("\n");
    while(1){
        if(t==9){
            printf("Stack Overflow");
            return;
        }
        else if(t==-1){
            printf("Stack Underflow");
            return;
        }
        else{
            printf("%d ",stack->data[t--]);
        }
    }
}

int main()
{
    int choice=0,item;
    struct Stack *stack = (int*)malloc(sizeof(int)*10); 
    stack->top=-1;
    printf("\nChoose your operation - ");
    printf("\n1.Add item\t2.Remove Item\t3.View Items\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    printf("\nEnter the item to be added : ");
    scanf("%d",&item);
    push(stack,item);
    break;

    case 2:
    printf("\nEnter the item to be removed : ");
    scanf("%d",&item);
    item = pop(stack);
    printf("\nItem removed : %d",item);
    break;

    case 3:
    printf("\nStack elements - ");
    peek(stack);
    break;
    
    default:
    printf("\nInvaid Input!");
    }
}