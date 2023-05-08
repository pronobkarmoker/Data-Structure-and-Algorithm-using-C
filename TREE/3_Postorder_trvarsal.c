#include <stdio.h>
#include <stdlib.h>

// LEFT - RIGHT - ROOT

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

void postorder(struct node *root)
{
    // struct node * root= (struct node*)malloc(sizeof(struct node));
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
        printf("  ");
    }
}
int main()
{
    // constructing the root node using function
    struct node *p = Createnode(4);
    struct node *p1 = Createnode(1);
    struct node *p2 = Createnode(6);
    struct node *p3 = Createnode(5);
    struct node *p4 = Createnode(2);

    //     4
    //    /\
    //   1  6
    //  /\
    // 5  2

    // linking the root node with left and right child
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postorder(p);
    return 0;
}
