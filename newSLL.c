#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ int data;
 struct node *link;
}NODE;

NODE*head;
void insertend(int ele)
{
    NODE *ptr;
    NODE *temp;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
        printf("empty");
    else
    {
        ptr->data=ele;
        if(head ==NULL)
        { 
            ptr->link=NULL;
            head=ptr;
        }
        else
        { 
            temp=head;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
        temp->link=ptr;
        ptr->link=NULL;

        }
    }
}
void insertfront(int ele)
{
    NODE *ptr;
    
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
        printf("empty");
    else
    {
            ptr->data=ele;
            ptr->link=head;
            head=ptr;
    }
    
}

int delfront(NODE* ptr)
{
    int x;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
        printf("empty");
    else
    {
        ptr=head->link;
        head->link=ptr->link;
        ptr->data=x;
        free(ptr);
        return x;
    }
}
int delend(NODE* ptr)
{
   
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
        printf("empty");
    else
    {
         ptr=head;
            while(ptr->link->link!=NULL)
            {
                ptr=ptr->link;
            }
        ptr->link=NULL;

       
    }
}
void display(NODE *ptr)
{
    if(ptr==NULL)
    {
        printf("empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->link;
        }

    }
}
int main()
{
    int ele,n;
    printf("enter n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the ele");
        scanf("%d",&ele);
        insertfront(ele);
    }
    delend(head);
    display(head);
  
}