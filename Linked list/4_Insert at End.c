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

struct node * InsertAtEnd(struct node * head , int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    struct node * p = head;

    while (p->next != NULL)
    {
        p=p->next;
    }
    p->next =ptr;
    ptr->data = data;
    ptr->next = NULL;

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
    InsertAtEnd(head , 100);
    travarsal(head);

    return 0;
}
