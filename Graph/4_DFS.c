#include<stdio.h>
int no_vertices;

void printGraph(int adjMat[][no_vertices])
{
    int i, j;
    for(i= 0 ; i< no_vertices; i++)
    {
        for (j= 0 ; j< no_vertices; j++)
        {
            printf("%d ",adjMat[i][j] );
        }
        printf("\n");
    }

}

void dfs(int adjMat[no_vertices][no_vertices], int visited[], int start){
    printf("%d\n", start);
    visited[start]= 1;
    
    for ( int i = 0; i < no_vertices; i++){
        if(visited[i] != 1 && adjMat[start][i]==1){
            
            dfs(adjMat, visited, i);
        }
    }
}

int main()
{
    int s, d, ch, start;
    printf("Enter the number of vertices :\n ");
    scanf("%d", &no_vertices);
    int adjMat[no_vertices][no_vertices], visited[no_vertices];

    int i, j;
    // for (i = 0; i < no_vertices; i++){
    //     visited[i]= 0;
    // }

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
        printf("Enter 1 for DFS : \n Enter 2 for print the matrix:\n Enter 3 for exit :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the vertex from which do you wanted to start : \n");
            scanf("%d", &start);
             for (int i = 0; i < no_vertices; i++){
            visited[i]= 0;
             }
            dfs(adjMat,visited, start);
            break;

        case 2:
            printGraph(adjMat);
            printf("\n");
            break;

        case 3:
            break;
        }

    } while (ch != 3);

    return 0;
}
