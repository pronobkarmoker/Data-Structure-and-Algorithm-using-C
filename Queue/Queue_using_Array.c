#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("empty");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int main()
{

    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (isEmpty(&q))
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("not empty\n");
    }

    enqueue(&q, 98);
    enqueue(&q, 34);
    enqueue(&q, 23);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 77);

    if (isEmpty(&q))
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("not empty\n");
    }

    printf("Dequeueing element %d\n", dequeue(&q));
    printf("Dequeueing element %d\n", dequeue(&q));

    return 0;
}