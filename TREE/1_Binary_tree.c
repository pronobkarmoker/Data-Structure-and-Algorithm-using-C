#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *Createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int main()
{

    /*
    //constructing the root node
    struct node * p = (struct node*)malloc(sizeof(struct node));
    p->data= 2;
    p->left =NULL;
    p->right= NULL;

    struct node * p1 = (struct node*)malloc(sizeof(struct node));
    p->data= 4;
    p1->left =NULL;
    p1->right= NULL;

    struct node * p2 = (struct node*)malloc(sizeof(struct node));
    p->data= 5;
    p2->left =NULL;
    p2->right= NULL;

    //linking the root node with left and right child
    p->left =p1;
    p->right= p2;

    */

    // constructing the root node using function
    struct node *p = Createnode(2);
    struct node *p1 = Createnode(1);
    struct node *p2 = Createnode(5);

    // linking the root node with left and right child
    p->left = p1;
    p->right = p2;

    return 0;
}