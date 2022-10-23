#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ int data;
 struct node *link;
}NODE;

NODE*ptr;

void insertfront(int ele)
{
    
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    NODE *first=ptr->link;
	ptr->link=temp;
	temp->link=first;
}

void display(NODE*ptr)
{
    NODE *cur=ptr->link;
    while(cur!=ptr)
	{
		printf("%d\t",cur->data);
		cur=cur->link;
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
  
    display(ptr);
  
}