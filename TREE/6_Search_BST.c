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


struct node * Search(struct node * root , int key){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == key){
        return root ;
    }
    else if( key <root->data){
        return Search(root->left , key);
    }
    else{
        return Search(root->right , key);
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

    

    struct node * n = Search(p,0);

    if(n!=NULL){
        printf(" FOUND : %d", n->data);
    }
    else{
        printf("Element not found");
    }

    return 0;
}