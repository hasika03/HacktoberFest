#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data;
    struct queue*link;
}QUEUE;

QUEUE *head,*ptr,*f=NULL,*r=NULL;
int n,ele;
int enqueue(int ele);
int dequeue();
void display();

int main()
{
    printf("enter n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
       enqueue(ele);
    }
    display();
    dequeue(); 
    display();
   
}

int enqueue(int ele)
{
    ptr=(QUEUE*)malloc(sizeof(QUEUE));
    if(ptr==NULL)
        printf("overflow");
    else{
        if(f==NULL)  
        {  
            ptr->data=ele;
            f= ptr;  
            r = ptr;   
            f-> link = NULL;  
            r -> link = NULL;  
        }  
        else   
        {  
            ptr->data=ele;
            r -> link = ptr;  
            r = ptr;
            r->link=NULL;  
        }  
    }
}

int dequeue()
{
    if(f==NULL)
        printf("empty");
    else
    {
        f=f->link;
    }
}

void display()
{
    ptr=f;
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->link;
    }
}
