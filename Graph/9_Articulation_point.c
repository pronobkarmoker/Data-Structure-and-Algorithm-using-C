#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int discoveryTime[MAX_VERTICES];
    int lowTime[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    bool isArticulationPoint[MAX_VERTICES];
};

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        graph->visited[i] = false;
        graph->isArticulationPoint[i] = false;
        graph->discoveryTime[i] = -1;
        graph->lowTime[i] = -1;
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void dfsArticulationPoints(struct Graph* graph, int vertex, int parent, int time) {
    int children = 0;
    graph->visited[vertex] = true;
    graph->discoveryTime[vertex] = time;
    graph->lowTime[vertex] = time;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i]) {
            if (!graph->visited[i]) {
                children++;
                dfsArticulationPoints(graph, i, vertex, time + 1);
                graph->lowTime[vertex] = min(graph->lowTime[vertex], graph->lowTime[i]);

                if (parent != -1 && graph->lowTime[i] >= graph->discoveryTime[vertex])
                    graph->isArticulationPoint[vertex] = true;
                if (parent == -1 && children > 1)
                    graph->isArticulationPoint[vertex] = true;
            } else if (i != parent) {
                graph->lowTime[vertex] = min(graph->lowTime[vertex], graph->discoveryTime[i]);
            }
        }
    }
}

void findArticulationPoints(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i])
            dfsArticulationPoints(graph, i, -1, 0);
    }

    printf("Articulation Points: ");
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->isArticulationPoint[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int numVertices = 7;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 3);
    addEdge(graph, 5, 6);

    findArticulationPoints(graph);

    return 0;
}


/*

1. `#include <stdio.h>`, `#include <stdlib.h>`, and `#include <stdbool.h>`: These lines include the standard input-output, standard library, and boolean headers, respectively, for handling input/output operations, memory management, and using boolean data types.
2. `#define MAX_VERTICES 100`: This line defines a constant `MAX_VERTICES` to specify the maximum number of vertices in the graph. You can adjust this value based on your requirements.
3. `struct Graph { ... };`: This block of code defines a structure `Graph` to represent a graph data structure.
4. `struct Graph* createGraph(int numVertices) { ... }`: This block of code defines the `createGraph` function that creates a graph with the specified number of vertices and initializes its properties such as adjacency matrix, discovery time, low time, visited array, and isArticulationPoint array.
5. `void addEdge(struct Graph* graph, int src, int dest) { ... }`: This block of code defines the `addEdge` function that adds an edge between two vertices in the graph by updating the adjacency matrix.
6. `int min(int a, int b) { ... }`: This block of code defines the `min` function that returns the minimum of two values `a` and `b`.
7. `void dfsArticulationPoints(struct Graph* graph, int vertex, int parent, int time) { ... }`: This block of code defines the `dfsArticulationPoints` function that performs a depth-first search to find the articulation points in the graph.
8. `void findArticulationPoints(struct Graph* graph) { ... }`: This block of code defines the `findArticulationPoints` function that initializes the necessary variables and calls `dfsArticulationPoints` for each unvisited vertex in the graph to find and print the articulation points.
9. `int main() { ... }`: This is the main function where the program execution begins.
10. `int numVertices = 7;`: This line declares and initializes the number of vertices in the graph.
11. `struct Graph* graph = createGraph(numVertices);`: This line creates a graph using the `createGraph` function and assigns it to the `graph` variable.
12. `addEdge(graph, 0, 1);` to `addEdge(graph, 5, 6);`: These lines add edges between vertices in the graph using the `addEdge` function.
13. `findArticulationPoints(graph);`: This line calls the `findArticulationPoints` function to find and print the articulation points in the graph.
14. `return 0;`: This line indicates the successful execution of the program and returns 0 to the operating system.

*/