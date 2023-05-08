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

void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

int isBST(struct node * root){
    struct node * pre = NULL;
    if(root != NULL){
        if(!isBST (root->left)){
            return 0;
        }
        if(pre != NULL && root->data<= pre->data){
            return 0;
        }
        pre = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main()
{


    // constructing the root node using function
    struct node *p = Createnode(5);
    struct node *p1 = Createnode(3);
    struct node *p2 = Createnode(6);
    struct node *p3 = Createnode(1);
    struct node *p4 = Createnode(4);

    //     5
    //    /\
    //   3  6
    //  /\
    // 1  4

    // linking the root node with left and right child
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    Inorder(p);
    printf("\n");
    printf("%d", isBST(p));

    return 0;
}