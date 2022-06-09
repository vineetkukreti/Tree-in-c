#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node * n3 = (struct node *)malloc(sizeof(struct node ));
    n3->info = data;
    n3->left = NULL;
    n3->right = NULL;
    return n3;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->info);
    }    

}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
         printf("%d ",root->info);
        inorder(root->right);
       
    }    

}
void  insertion(struct node *root,int data)
{
      struct node *prev = NULL;
      while(root!=NULL)
      {
          prev = root;
          if((root)->info == data)
                return ;
         else if((root)->info > data)
         {
             root = (root)->left;
         }
         else
         {
               root = (root)->right;
         }
      }
        struct node *newnode = createnode(data);
        if(prev->info > data)
            prev->left = newnode;
        else
            prev->right = newnode;
}
   struct node *FindMin(struct node *root)
   {
       
       while(root&&root->left!=NULL)
       {
           root = root->left;
       }
       printf("Inorder Successor : %d\n",root->info);
       return root;
   }
struct node *deletenode(struct node *root,int data)
{
    //search the node 

   if(root==NULL) return root;   
   else if(data < root->info) 
		root->left = deletenode(root->left,data);
   else if(data > root->info)
   		root->right = deletenode(root->right,data);
   // when node is found
   else
   {

        if(root->left==NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
            
        }
        else if(root->right ==NULL)
        {
            struct node *p = root;
            root = root->left;
            free(p);
            
        }
        else
        {
            struct node *temp = FindMin(root->right);
            root->info = temp->info;
            root->right = deletenode(root->right,root->info);
        }
   
   }
    return root;
   }

int main()
{
    int data;
    struct node *p  = createnode(4);
    struct node *p1 = createnode(2);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(3);
    struct node *p5 = createnode(5);
    struct node *p6 = createnode(7);
  
  
  	p->left = p1;
  	p->right = p2;
  	p1->left = p3;
  	p1->right = p4;
  	p2->left = p5;
    p2->right = p6;
    printf("Before deletion : ");
    inorder(p);
    printf("\nAfter deletion  : ");
       
       // insertion(p,data);
    deletenode(p,3);
      inorder(p);

    
    return 0;
}