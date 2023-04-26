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

struct node *DeleteIndex(struct node*head, int index){
    struct node * p = head;
    struct node * q = head->next;

    
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    
    p->next = q->next;
    free(q);

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
    int index;
    

    travarsal(head);

    DeleteIndex(head , 2);

    travarsal(head);

    return 0;
}
