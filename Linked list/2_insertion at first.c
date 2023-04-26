#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void travarsal(struct node * ptr){
    while(ptr != NULL){
        printf("Element : %d \n", ptr->data);
        ptr= ptr->next;
    }
}

struct node * InsertAtFirst(struct node *head , int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;

    return ptr;

}

int main (){

    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * second = (struct node*)malloc(sizeof(struct node));
    struct node * third = (struct node*)malloc(sizeof(struct node));
    struct node * fourth = (struct node*)malloc(sizeof(struct node));

    head->data = 21;
    head->next = second;

     second->data = 12;
    second->next = third;

    third->data = 1;
    third->next = fourth;

    fourth->data = 2;
   fourth->next = NULL;

   travarsal(head);
   head = InsertAtFirst(head , 67);
   travarsal(head);


   return 0;
}