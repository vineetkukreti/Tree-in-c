#include<stdio.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;
};
void create_root(struct node **root,int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node ));
    newnode->info = data;
    newnode->right = NULL;
    if(*root==NULL)
    {
        newnode->right = NULL;
        newnode->left = NULL;
    }
    else
    {
        
    }

}
int main()
{
    struct node *root=NULL;
    int data,choice;
    printf("1.create node\n");
    while(1)
    {
     scanf("%d",&choice);
     switch (choice)
     {
     case 1:
        printf("Enter the element : ");
        scanf("%d",&data);
         create_root(&root,data);
         break;
     
     default:
         break;
     }

    }
    return 0;
}