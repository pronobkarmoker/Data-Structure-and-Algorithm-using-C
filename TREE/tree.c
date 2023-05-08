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

struct node *insertleft(struct node * root , int data){
    root->left = Createnode(data);
    return root->left;
}

struct node *insertright(struct node * root , int data){
    root->right = Createnode(data);
    return root->right;
}

void inordertravarsal(struct node *root){
    if(root != NULL){
        inordertravarsal(root->left);
        printf("%d " , root ->data);
        inordertravarsal(root->right);
    }
}

void pretravarsal(struct node *root){
    if(root != NULL){
        printf("%d " , root ->data);
        pretravarsal(root->left);
        pretravarsal(root->right);
    }
}

void posttravarsal(struct node *root){
    if(root != NULL){
        posttravarsal(root->left);
        posttravarsal(root->right);
        printf("%d " , root ->data);
    }
}





int main (){
    struct node * root = Createnode(1);
    insertleft(root , 12);
    insertright(root , 9);

    insertleft(root->left , 5);
    insertright(root->left ,6);

    insertleft(root->left->right , 2);
    insertright(root->left->right ,3);

    printf("Inorder travarsal : ");
    inordertravarsal(root);
    printf("\n");
    printf("preorder travarsal : ");
    pretravarsal(root);
    printf("\n");
    printf("postorder travarsal : ");
    posttravarsal(root);

    search(root, 6);

    return 0;
    

}