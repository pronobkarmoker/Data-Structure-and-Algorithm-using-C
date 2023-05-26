#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

int stack[MAX_VERTICES];
int top = -1;

void push(int vertex) {
    stack[++top] = vertex;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void DFS_Visit(int u, int numVertices, int visited[MAX_VERTICES], int adjMatrix[MAX_VERTICES][MAX_VERTICES]) {
    visited[u] = 1;

    for (int v = 0; v < numVertices; v++) {
        if (adjMatrix[u][v] == 1 && visited[v] == 0) {
            DFS_Visit(v, numVertices, visited, adjMatrix);
        }
    }

    push(u); // Push the vertex to the stack after all its outgoing edges have been visited
}

void topologicalSort(int numVertices, int adjMatrix[MAX_VERTICES][MAX_VERTICES]) {
    int visited[MAX_VERTICES] = {0};

    for (int u = 0; u < numVertices; u++) {
        if (visited[u] == 0) {
            DFS_Visit(u, numVertices, visited, adjMatrix);
        }
    }

    printf("Topological Sort: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
}

int main() {
    int numVertices = 6;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };

    topologicalSort(numVertices, adjMatrix);

    return 0;
}


/*Certainly! Let's go through the code step by step and explain its functionality:

1. The code starts by including the necessary header files and defining the maximum number of vertices as `MAX_VERTICES`.

2. The `stack` array and the `top` variable are declared to implement a stack data structure. This stack will be used to store the vertices in the topological order.

3. The `push` function is used to insert an element into the stack by incrementing the `top` variable and assigning the element to the corresponding index in the `stack` array.

4. The `pop` function is used to retrieve and remove the top element from the stack by returning the value at the current `top` index and then decrementing the `top` variable.

5. The `isEmpty` function checks if the stack is empty by checking if the `top` variable is equal to -1. If it is, the function returns 1, indicating that the stack is empty; otherwise, it returns 0.

6. The `DFS_Visit` function implements the depth-first search traversal and topological sorting for a given vertex `u`. It takes the current vertex `u`, the number of vertices, an array `visited` to keep track of visited vertices, and the adjacency matrix `adjMatrix` as parameters.

   - It marks the current vertex `u` as visited by setting `visited[u]` to 1.
   - It then iterates over all the vertices `v` and checks if there is an edge from `u` to `v` (by checking `adjMatrix[u][v] == 1`) and if `v` has not been visited yet (`visited[v] == 0`).
   - If the conditions are met, it recursively calls `DFS_Visit` on the unvisited vertex `v`.
   - After visiting all the adjacent vertices, it pushes the current vertex `u` onto the stack.

7. The `topologicalSort` function performs the topological sorting for the entire graph. It takes the number of vertices and the adjacency matrix as parameters.

   - It initializes the `visited` array to keep track of visited vertices.
   - It iterates over all the vertices and checks if a vertex has not been visited yet.
   - If a vertex has not been visited, it calls the `DFS_Visit` function to perform the depth-first search traversal starting from that vertex.
   - Once all the vertices have been visited, it prints the topological order by popping the vertices from the stack and printing them.

8. In the `main` function, the number of vertices and the adjacency matrix are defined.

9. The `topologicalSort` function is called with the number of vertices and the adjacency matrix as arguments.

10. Finally, the topological order is printed, which represents the sorted order of vertices in the directed graph.

I hope this explanation clarifies the functionality of the code. Let me know if you have any further questions!*/