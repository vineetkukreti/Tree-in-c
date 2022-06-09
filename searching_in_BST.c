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
struct node*  search(struct node *p,int ele)// RECURSIVE  CODE
{
    if(p==NULL)
    {
        return NULL;
    } 
    else if(p->info==ele)
        return p;
    else if(p->info > ele)
        return search(p->left,ele);
    else
        return search(p->right,ele);

}

struct node* searchItr(struct node *p,int ele)
{
    while (p!=NULL)
    {
         if(p->info==ele)
            return p;
         else if(p->info > ele)
             p = p->left;
         else
             p = p->right;
    }
    
   return NULL;
}

int main()
{
    int data,ele;
      struct node *p  = createnode(6);       
    struct node *p1 = createnode(4);
    struct node *p2 = createnode(11);
    struct node *p3 = createnode(2);
    struct node *p4 = createnode(3);
    struct node *p5 = createnode(85);
  
    p->left = p1;
    p->right = p2\;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    // while(1){
         inorder(p);
    // printf("\nEnter the ele = ");
    // scanf("%d",&ele);
    
    // struct node *e = search(p,ele);
    // if(e!=NULL)
    //     printf("<<< \n %d is present\n >>>",e->info);
    // else
    //     printf("\n\nElememt is not present\n\n");

    // }
    printf("\nEnter the ele = ");
    scanf("%d",&ele);
    struct node *e = searchItr(p,ele);
     if(e!=NULL)
        printf("<<< \n %d is present\n >>>",e->info);
    else
        printf("\n\nElememt is not present\n\n");

 return 0;
    }
   