#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Travarsal(struct node *head)
{
    struct node *ptr = head;

    printf("Element : %d \n", ptr->data);
    ptr = ptr->next;

    while (ptr != head)
    {
        printf("Element : %d \n", ptr->data);
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

    second->data = 9;
    second->next = third;

    third->data = 10;
    third->next = forth;

    forth->data = 11;
    forth->next = head;

    Travarsal(head);

    return 0;
}