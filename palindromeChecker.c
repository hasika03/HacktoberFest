// PALINDROME CHECKER
// EX : ATKTA = PALINDROME && ABCD != PALINDROME
#include <stdio.h>
#include <stdlib.h>


struct node { // creating the structure 
	char info;
	struct node *link;
}*stack=NULL;


void linkqinsert(char data);  // function declaration  
void delq();  // function declaration
void dellast();  // function declaration   

struct node* front=NULL;  // initialization variable
struct node* rear=NULL;// initialization 
void push(char pc){  // push front side entry to reduce steps
	struct node *nNode=(struct node *)malloc(sizeof(struct node));	
    nNode->info=pc;
    if (stack==NULL){ //empty
        nNode->link=NULL;
    }
    else
    {
        nNode->link=stack;
    }
    stack=nNode;
    //printf("Pushed %c\n",pc)  ; 
}

void pop(void){
    if (stack!=NULL){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp=stack;   // printf("popped %c\n",temp->info);
        //char info=temp->info; // storing for val check
        stack=temp->link;
        free(temp);
    }

    //return info;
}


void display(struct node *head ){
	
	struct node* nnode=(struct node*)malloc(sizeof(struct node));// assigning memory to new node
	nnode=head;
	if (nnode== NULL)// Empty
	{
		//printf("Our queue is empty.\n");// Empty
        exit(1);
	}

		printf("Our queue is :   ");
		while (nnode !=NULL)// upto the end
		{
			printf(" %c --->", nnode->info);// printing the data
			nnode=nnode->link;// going to the next node
		}
        printf(" NULL \n");// at last it is pointint to the null

}// end
int count(char str[20]){
    int i=0,j=0;
    while (str[i+1]!='\0')
    {
        j++;
        i++;
    }
    return j;
}

void main(void){
    char str[20],ch,pc;int i=0,j,k;

    printf("Input the string : ");
    
    fgets(str, sizeof str, stdin);
    j=count(str);
    //printf("%d\n",j);
    if (j%2 !=0){  // for odd case removing the middle term
        k=j/2 +1;
    }
    else
    {
        k=j+1;
    }
    //printf("%d\n",k);
    while (str[i+1]!='\0')
    {
        if (i+1 !=k) // for odd case removing the middle term
        {
            linkqinsert(str[i]);
            push(str[i]);
        }
        i++;
    }
     
    //display(front);display(stack); // ok
    for(int diff='a'-'A';stack !=NULL;)// diff=difference of character
    {
        if(front->info==stack->info ||front->info==stack->info +diff||front->info==stack->info -diff )
        {
            pop();
            delq();
        }
        else
        {
            printf("\n    String is not a palindrome    \n\n");
            exit(1);
        }
    }
    printf("\n    String is a palindrome    \n\n");
    
}

void linkqinsert(char data){
    struct node* nnode=(struct node*)malloc(sizeof(struct node));// assigning memory to new node
    // taking user input
    nnode->info=data;// assigning the data
	nnode->link=NULL;// linking to the NULL
	if (rear==NULL)// empty queue
	{
		front=nnode;
		rear=front;
	}
	else{ // contains some nodes
		rear->link=nnode;//linking the last node
		rear=nnode;//converting last node to rear for further insertion
	}
   
}// end
void delq(){ //delete 2 same char or delcare Not a palindrome
    struct node* nnode=(struct node*)malloc(sizeof(struct node));
    nnode=front;// to delete
    if (front!=NULL) // Empty or 1 element
	{
        front=front->link;
        free(nnode);
	}
}
void dellast(){
	struct node *temp;
    temp=front;
	if(rear==NULL) // if no list exist
	{
		//printf("Empty.\n");
	}
	else // if list exist deleting the last node
	{
        while (temp->link !=rear)
        {
            temp=temp->link; // next node
        }
        rear=temp;
        temp->link=NULL;
        free(temp->link);
	}
} //end