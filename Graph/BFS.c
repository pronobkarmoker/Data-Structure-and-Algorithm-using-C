#include<stdio.h>
#include <stdio.h>

int n = 10, front = -1, rear = -1;
int arr[10];
int vis[10];
int graph[10][10];

void bfs(int num){
    for(int i=0; i<n; i++){
        if(graph[num][i] && !vis[i]){
            arr[++rear] = i;
            vis[i] = 1;
        }
    }
    if(front<rear){
        bfs(arr[front++]);
    }
}

void bfsHelper(int num){
    arr[++rear] = num;
    vis[num] = 1;
    bfs(num);
}

int main(){
    printf("Enter number of node : \n");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n printing graph...\n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    bfsHelper(0);

    for(int k=0; k<n; k++){
        printf("%d  ", arr[k]);
    }
}
