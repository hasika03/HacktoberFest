# include<stdio.h>  
# include<stdlib.h>  
  
typedef struct node  
    {  
    int data;  
    struct node *right;
    struct node *left;  
}NODE;  

NODE *root=NULL; // similar to head

NODE *createnode(int ele)
{
    NODE *temp=malloc(sizeof(NODE));
    temp->data=ele;                    // can also be done in inset
    temp->right=NULL;
    temp->left=NULL;
}
void insertion(NODE **temp,int ele)
{
    if(*temp==NULL)
        *temp=createnode(ele);
    else if(ele< (*temp)->data)
        insertion(&(*temp)->left, ele);
    else
        insertion(&(*temp)->right, ele);
}
void inorder(NODE *temp) // first left then print then right LVR
{
    if(temp == NULL)  
        return;
    inorder(temp->left);
    printf("%d",temp->data);
    inorder(temp->right);
}

void preorder(NODE *temp)   // first print then left then right        VLR
{
    if(temp == NULL)
        return;
    else{
        printf("%d",temp->data);
        preorder(temp->left); // traverses thru left ele, prints data
        preorder(temp->right);// when left becomes null does the same for right 
    }
       
}

void postorder(NODE *temp)// LRV
{
    if(temp == NULL)
        return;
    else{
        postorder(temp->left); // first left then right then print 
        postorder(temp->right);
        printf("%d",temp->data); 
    }
}

int main()
{
     int data, ch;
        while (1) {
                printf("\n1. Insertion\n2. Pre-order\n");
                printf("3. Post-order\n4. In-order\n");
                printf("5. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter ur data:");
                                scanf("%d", &data);
                                insertion(&root, data);
                                break;
                        case 2:
                                preorder(root);
                                break;
                        case 3:
                                postorder(root);
                                break;
                        case 4:
                                inorder(root);
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("U've entered wrong opetion\n");
                                break;
                }
        }
        return 0;
  }

void delete();