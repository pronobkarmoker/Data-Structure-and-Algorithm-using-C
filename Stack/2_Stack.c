#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Travarsal(struct node *p)
{
    while (p != NULL)
    {
        printf("Element : %d \n", p->data);
        p = p->next;
    }
}

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int data)
{
    if (isFull(top))
    {
        printf("Stack overflow \n");
    }
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = top;
    top = n;
    return top;
}

int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    struct node *top = NULL;

    top = push(top, 69);
    top = push(top, 45);
    top = push(top, 55);
    top = push(top, 66);
    top = push(top, 89);

    int element = pop(&top);
    printf("Popped element is %d\n", element);

    Travarsal(top);

    return 0;
}
