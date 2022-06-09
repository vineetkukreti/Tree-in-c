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

int main()
{
    int data;
    struct node *p  = createnode(2);       
    struct node *p1 = createnode(4);
    struct node *p2 = createnode(11);
    struct node *p3 = createnode(27);
    struct node *p4 = createnode(56);
    struct node *p5 = createnode(85);
  
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    preorder(p);
    printf("\n");
    postorder(p);
     printf("\n");
    inorder(p);
    return 0;
}