#include <stdio.h>
int no_vertices;

void printGraph(int adjMat[][no_vertices])
{
    int i, j;
    for (i = 0; i < no_vertices; i++)
    {
        for (j = 0; j < no_vertices; j++)
        {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }
}

void bfs(int adjMat[][no_vertices], int start)
{
    int visited[no_vertices];
    int queue[no_vertices];
    int front = -1;
    int rear = -1;

    for (int i = 0; i < no_vertices; i++)
    {
        visited[i] = 0;
    }
    front++;
    queue[++rear] = start;
    visited[start] = 1;

    while (front <= rear)
    {
        start = queue[front++];
        printf("%d\t", start);

        for (int i = 0; i < no_vertices; i++)
        {
            if (adjMat[start][i] == 1 && visited[i] != 1)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int s, d, ch, start;
    printf("Enter the number of vertices :\n ");
    scanf("%d", &no_vertices);
    int adjMat[no_vertices][no_vertices];

    int i, j;
    for (i = 0; i < no_vertices; i++)
    {
        for (j = 0; j < no_vertices; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    while (s != -1 && d != -1)
    {
        printf("enter an edge fromnode(o to %d) to node(0 to %d) : ", no_vertices, no_vertices);
        scanf("%d%d", &s, &d);
        adjMat[s][d] = 1;
        adjMat[d][s] = 1;
    }

    do
    {
        printf("Enter 1 for BFS : \n Enter 2 for print the matrix:\n Enter 3 for exit :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the vertex from which do you wanted to start : \n");
            scanf("%d", &start);
            bfs(adjMat, start);
            break;

        case 2:
            printGraph(adjMat);
            break;

        case 3:
            break;
        }

    } while (ch != 3);

    return 0;
}
