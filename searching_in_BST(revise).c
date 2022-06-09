#include<stdio.h>
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
    p1->left  = p4;
    p1->right = p5;
    p2->left  = p6;
    p2->right = p7;

    inorder(root);
    return 0;
}