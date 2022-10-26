#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int data;
    struct stack*link;
}STACK;

STACK *head;
int top=-1,n,ele;
STACK *ptr;


void display();
int push(int ele);
int pop();
int main()
{
    printf("enter n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        push(ele);
    }
    display();
    pop(); 
    display();
   
}

int push(int ele)
{
    ptr=(STACK*)malloc(sizeof(STACK));
    if(top>=n-1)
        printf("overflow");
    else
    {
        ptr->data=ele;
        ptr->link=head;
        head=ptr;
    }

}

int pop()
{
    
    if(head==NULL){
        printf("empty list");
    }

    else
    {
        ptr=head->link;
        head->link=ptr->link;
    }
}

void display()
{
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->link;
    }
}