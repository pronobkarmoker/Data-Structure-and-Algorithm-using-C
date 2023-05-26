#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("EMPTY\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        val = q->arr[q->f];
    }
    return val;
}

int main()
{
    struct circularQueue q;
    int size = 100;
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

    enqueue(&q, 420);
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