#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}NODE;
typedef struct Cq{
	NODE *f,*r;
}CQ;
void enqueue(CQ *ptr, int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	if(ptr->f==NULL)
	{
		ptr->f=ptr->r=temp;
	}
	ptr->r->link=temp;
	temp->link=ptr->f;
	ptr->r=temp;
}
void display(CQ* ptr)
{
	if(ptr->f==NULL)
	{
		printf("underflow condition\n");
		return;
	}
	NODE *cur=ptr->f;
	while(cur!=ptr->r)
	{
		printf("%d\t",cur->data);
		cur=cur->link;
	}
	printf("%d\t",cur->data);
}
int dequeue(CQ *ptr)
{ 
	int x;
	if(ptr->f==NULL)
		return 9999;
	else{
		if(ptr->f==ptr->r)
		{
			x=ptr->f->data;
			free(ptr->f);
			ptr->f=ptr->r=NULL;
			return(x);
		}
		NODE *second=ptr->f->link;
		x=ptr->f->data;
		free(ptr->f);
		ptr->r->link=second;
		ptr->f=second;
		return(x);
	}
}
		
	

int main()
{
	CQ *ptr=malloc(sizeof(CQ));
	ptr->f=ptr->r=NULL;
	int ch,ele,x;
	while(1)
	{
		printf("1.enqueue\n 2.dequeue\n 3.display\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the ele\n");
					scanf("%d",&ele);
					enqueue(ptr,ele);
					break;
			case 2:x=dequeue(ptr);
			if(x==9999)
				printf("underflow condition\n");
			else
				printf("deleted element is %d\n",x);
			break;
			case 3:display(ptr);
			break;
		}
	}
}