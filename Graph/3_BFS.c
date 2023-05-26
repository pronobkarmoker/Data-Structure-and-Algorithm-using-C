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

    //BFS

    int node;
    int i= 0;
    int visited[7]= {0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("%d", i);
    visited[i] = 1;
    enqueue(&q , i);

    while(!isEmpty(&q)){
        int node =dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j]== 0){
                printf("%d", j);
                visited[j]= 1;
                enqueue(&q, j);
            }
        }
        
    }

    return 0;
}