#include<stdio.h>
int no_vertices;
#define WHITE 0;
#define GREY -2;
#define BLACK 1;
int time ;
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

void dfs(int adjMat[no_vertices][no_vertices], int start, int visited ){
    int color[no_vertices];
    int prev[no_vertices];
    int D[no_vertices];
    int F[no_vertices];

    for (int i = 0; i < no_vertices; i++)
    {
        color[i]= WHITE;
        prev[i]=NULL;
        F[i]=-1;
        D[i]= -1;
    }
    time= 0;

    for (int i = 0; i < no_vertices; i++)
    {
        if (color[i]==0)
        {
            dfs(adjMat);
        }
        
    }
    
    
}

int main()
{
    int s, d;
    printf("Enter the number of vertices :\n ");
    scanf("%d", &no_vertices);
    int adjMat[no_vertices][no_vertices];

    int i,j;
    for(i=0; i<no_vertices; i++)
    {
        for(j=0; j<no_vertices; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    while(s!= -1 && d!= -1)
    {
        printf("enter an edge fromnode(o to %d) to node(0 to %d) : ",no_vertices,no_vertices);
        scanf("%d%d", &s, &d);
        adjMat[s][d]=1;
        adjMat[d][s]=1;

    }

    printGraph(adjMat);
    return 0;
}


