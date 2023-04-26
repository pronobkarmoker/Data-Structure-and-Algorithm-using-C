#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};

void travarsal(struct node *ptr){

    while(ptr != NULL)
    {
        printf("element : %d \n", ptr->data);
        ptr= ptr->next;
    }
    
}

struct node * InsertAfterNode(struct node*head , struct node *preNode , int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    
    ptr->data = data;
   
    ptr->next= preNode->next;
    preNode->next = ptr;
    return head;
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* forth = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;

    third-> data = 10;
    third->next = forth;

    forth->data =11;
    forth->next= NULL;

    travarsal(head);
    head = InsertAfterNode(head , second , 100);
    travarsal(head);

    return 0;
}
