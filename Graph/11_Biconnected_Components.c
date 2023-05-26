#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int time = 0;

// Function to find minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Depth First Search function for finding Biconnected Components
void dfsBiconnectedComponents(int u, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int discTime[], int lowTime[], int parent[], int* count) {
    visited[u] = 1;
    discTime[u] = lowTime[u] = ++time;
    int children = 0;

    for (int v = 0; v < MAX_VERTICES; v++) {
        if (adjMatrix[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfsBiconnectedComponents(v, adjMatrix, visited, discTime, lowTime, parent, count);

                lowTime[u] = min(lowTime[u], lowTime[v]);

                if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && lowTime[v] >= discTime[u])) {
                    printf("%d ", u);
                    while (u != v) {
                        printf("%d ", v);
                        v = parent[v];
                    }
                    printf("\n");
                    (*count)++;
                }
            } else if (v != parent[u])
                lowTime[u] = min(lowTime[u], discTime[v]);
        }
    }
}

// Function to find Biconnected Components in a graph
void findBiconnectedComponents(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int visited[MAX_VERTICES] = {0};
    int discTime[MAX_VERTICES];
    int lowTime[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int count = 0;

    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1;
        visited[i] = 0;
        discTime[i] = 0;
        lowTime[i] = 0;
    }

    for (int u = 0; u < numVertices; u++) {
        if (!visited[u])
            dfsBiconnectedComponents(u, adjMatrix, visited, discTime, lowTime, parent, &count);
    }

    printf("Total Biconnected Components: %d\n", count);
}

int main() {
    int numVertices = 7;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };

    findBiconnectedComponents(adjMatrix, numVertices);

    return 0;
}


/*

1. `#include <stdio.h>` and `#include <stdlib.h>`: These lines include the standard input-output and standard library headers, respectively, for handling input/output operations and memory management.
2. `#define MAX_VERTICES 100`: This line defines a constant `MAX_VERTICES` to specify the maximum number of vertices in the graph. You can adjust this value based on your requirements.
3. `int time = 0;`: This line initializes a variable `time` to keep track of the discovery time during DFS traversal.
4. `int min(int a, int b)`: This line defines a function `min` that returns the minimum of two values `a` and `b`.
5. `void dfsBiconnectedComponents(int u, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int discTime[], int lowTime[], int parent[], int* count)`: This line declares the function prototype for performing DFS traversal and finding biconnected components.
6. `void findBiconnectedComponents(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices)`: This line declares the function prototype for finding and printing the biconnected components of the graph.
7. `int main()`: This line marks the beginning of the main function, where the execution of the program starts.
8. `int visited[MAX_VERTICES] = {0};`, `int discTime[MAX_VERTICES];`, `int lowTime[MAX_VERTICES];`, and `int parent[MAX_VERTICES];`: These lines declare arrays `visited`, `discTime`, `lowTime`, and `parent` to keep track of visited vertices, discovery time, low time, and parent vertices during DFS traversal.
9. `int count = 0;`: This line initializes a variable `count` to keep track of the number of biconnected components.
10. `for (int i = 0; i < numVertices; i++) { ... }`: This block of code initializes the arrays `parent`, `visited`, `discTime`, and `lowTime` for each vertex in the graph.
11. `for (int u = 0; u < numVertices; u++) { ... }`: This block of code iterates through each vertex of the graph and checks if it is visited. If not visited, it calls the `dfsBiconnectedComponents` function to perform DFS traversal and find biconnected components.
12. `if (!visited[u]) dfsBiconnectedComponents(u, adjMatrix, visited, discTime, lowTime, parent, &count);`: This line checks if the vertex `u` is not visited. If so, it calls the `dfsBiconnectedComponents` function to perform DFS traversal and find biconnected components starting from `u`.
13. `void dfsBiconnectedComponents(int u, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int discTime[], int lowTime[], int parent[], int* count) { ... }`: This block of code defines the `dfsBiconnectedComponents` function that performs DFS traversal, updates discovery time and low time, and finds biconnected components.
14. `visited[u] = 1;`: This line marks the vertex `u` as visited.
15. `discTime[u] = lowTime[u] = ++time;`: This line updates the discovery time and low time of vertex `u` and increments the `time` variable.
16. `for (int v = 0; v <

 MAX_VERTICES; v++) { ... }`: This block of code iterates through all the vertices adjacent to vertex `u`.
17. `if (adjMatrix[u][v]) { ... }`: This line checks if there is an edge between vertices `u` and `v` in the adjacency matrix.
18. `if (!visited[v]) { ... }`: This line checks if vertex `v` is not visited. If so, it is considered a child of vertex `u` in the DFS tree.
19. `children++;`: This line increments the `children` variable to count the number of children of vertex `u`.
20. `parent[v] = u;`: This line sets the parent of vertex `v` as `u`.
21. `dfsBiconnectedComponents(v, adjMatrix, visited, discTime, lowTime, parent, count);`: This line recursively calls the `dfsBiconnectedComponents` function to perform DFS traversal starting from vertex `v`.
22. `lowTime[u] = min(lowTime[u], lowTime[v]);`: This line updates the low time of vertex `u` based on the low time of vertex `v`.
23. `if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && lowTime[v] >= discTime[u])) { ... }`: This line checks if vertex `u` is an articulation point by comparing its discovery time with the low time of vertex `v`.
24. `printf("%d ", u);`: This line prints the articulation point.
25. `while (u != v) { ... }`: This block of code prints the biconnected component by backtracking from vertex `v` to `u` using the parent array.
26. `printf("\n");`: This line prints a newline character to separate different biconnected components.
27. `(*count)++;`: This line increments the `count` variable to keep track of the number of biconnected components.
28. `void findBiconnectedComponents(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) { ... }`: This block of code defines the `findBiconnectedComponents` function that initializes necessary variables and calls the `dfsBiconnectedComponents` function for each unvisited vertex.
29. `printf("Total Biconnected Components: %d\n", count);`: This line prints the total number of biconnected components found.
30. `return 0;`: This line indicates the successful execution of the program and returns 0 to the operating system.
*/