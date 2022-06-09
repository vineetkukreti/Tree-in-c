#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int info;
    struct node *left,*right;
    int height;
};
int getHeight(struct node *n)
{
    if(n==NULL)
        return 0;
    return n->height;
}
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node ));
    newnode->height = 1;
    newnode->info = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int getbalanceFactor(struct node *n)
{
    if(n==NULL)
        return 0;
    return getHeight(n->left->height - n->right->height)
}
struct node *leftrotate(struct node * y)
{
    struct node *x = y->left;
}
int main()
{
    
}

