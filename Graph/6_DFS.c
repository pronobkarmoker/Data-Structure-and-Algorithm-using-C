#include <stdio.h>

int n, i, j, vis[10], que[10], front = 0, rear = -1;
int vt[10], ft[10], time = 0;
int adj[6][6];
 
void dfs(int v)
{
if(!vis[v]){
que[++rear] = v;
vis[v] = 1;
time = time+1;
vt[v] = time;
}
for(int i=0; i<n; i++){
if(adj[v][i] && !vis[i]){

que[++rear] = i;
vis[i] = 1;

time = time + 1;
vt[i] = time;

dfs(que[++front]);

time = time + 1;
ft[i] = time;
printf("%d  ", time);
}
}
}
 
void main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        que[i] = 0;
        vis[i] = 0;
    }

    printf("Enter graph [Matrix] :    \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
}
}

    printf("Enter starting point: ");
    scanf("%d", &v);
    dfs(v);
    for (i = 0; i < n; i++){
    printf("%d  ", que[i]);
}
printf("\n");

for (i = 0; i < n; i++){
    printf("%d  ", vt[i]);
}
printf("\n");

for (i = 0; i < n; i++){
    printf("%d  ", ft[i]);
}
printf("\n");
}
