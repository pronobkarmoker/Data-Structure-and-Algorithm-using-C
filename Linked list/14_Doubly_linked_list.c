#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pre;
};

void travarsal(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *forth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    head->pre = NULL;

    second->data = 9;
    second->next = third;
    second->pre = head;

    third->data = 10;
    third->next = forth;
    third->pre = second;

    forth->data = 11;
    forth->next = NULL;
    forth->pre = third;

    travarsal(head);

    return 0;
}
