#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int info;
    struct node *right,*left;

};
struct node * create_node(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node ));
    newnode->left = NULL;
    newnode->info = data;
    newnode->right = NULL;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d  ",root->info);
        inorder(root->right);
    }
}
struct node * search(struct node *root,int key)
{
        if(root==NULL)
        {
             printf("Element not found!!!!");
             return NULL;
        }
        else if(root->info == key)
        {
            printf(" --- Element found --- ");
            return root;
        }
        else if(root->info > key)
        {
            return search(root->left,key);
        }
        else
        {
            return search(root->right,key);
        }
}
struct node * insertion(struct node *root,int data)
{
    struct node *prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(root->info==data)
        {
            return NULL;
        }
        else if(root->info > data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    if(prev->info > data)
    {
        prev->left = newnode;
    }
    else
    {
       prev->right = newnode;
    }
}
int main()
{
    //    10
    //   /   \
    //  8     34
    // / \   /  \
    // 6  9 12   55
    struct node *root = NULL;
    struct node *p1 = create_node(10);
    struct node *p2 = create_node(8);
    struct node *p3 = create_node(34);
    struct node *p4 = create_node(6);
    struct node *p5 = create_node(9);
    struct node *p6 = create_node(12);
    struct node *p7 = create_node(55);


    root = p1;
    p1->left  = p2;
    p1->right = p3;
    p2->left  = p4;
    p2->right = p5;
    p3->left  = p6;
    p3->right = p7;

    inorder(root);
 
    root =  insertion(root,3);
     inorder(root);
    return 0;
}