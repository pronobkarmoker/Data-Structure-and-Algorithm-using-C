#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void DFS(struct Graph* graph, int vertex, bool visited[]);
struct Graph* transposeGraph(struct Graph* graph);
void DFSUtil(struct Graph* graph, int vertex, bool visited[]);

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
}

void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

struct Graph* transposeGraph(struct Graph* graph) {
    struct Graph* transpose = createGraph(graph->numVertices);

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            transpose->adjacencyMatrix[i][j] = graph->adjacencyMatrix[j][i];
        }
    }

    return transpose;
}

void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void printStronglyConnectedComponents(struct Graph* graph) {
    bool visited[MAX_VERTICES] = {false};

    // Perform DFS on the original graph
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }

    // Transpose the graph
    struct Graph* transpose = transposeGraph(graph);

    // Reset visited array
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    printf("\nStrongly Connected Components:\n");

    // Perform DFS on the transpose graph using finishing times
    while (!isEmpty(stack)) {
        int vertex = pop(stack);
        if (!visited[vertex]) {
            DFSUtil(transpose, vertex, visited);
            printf("\n");
        }
    }
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

    printStronglyConnectedComponents(graph);

    return 0;
}


/*The provided code is a C program that performs a Depth First Search (DFS) on a graph and its reverse. It takes user input to create a graph represented by an adjacency matrix and then performs DFS on the graph and its reverse.

The program consists of the following functions:

1. `createGraph()`: This function prompts the user to enter the number of vertices and edges in the graph. It then initializes the adjacency matrix and adds edges to the graph based on user input.

2. `DFS()`: This function performs Depth First Search starting from a given vertex. It marks the current vertex as visited, prints it, and recursively explores all unvisited adjacent vertices.

3. `reverseGraph()`: This function creates the reverse of the original graph. It copies the elements of the original adjacency matrix to a reverse matrix by swapping rows and columns.

4. `DFSUtil()`: This function is a utility function for Depth First Search on the reversed graph. It marks the current vertex as visited, prints it, and recursively explores all unvisited adjacent vertices.

The program executes the following steps:

1. It includes the necessary header files for input/output, dynamic memory allocation, and boolean data type.

2. It defines a constant `MAX_VERTICES` to represent the maximum number of vertices in the graph.

3. It declares variables to store the number of vertices, number of edges, and the adjacency matrix.

4. It defines the function prototypes for the graph operations.

5. The `main()` function is the entry point of the program.

6. Inside `main()`, the `createGraph()` function is called to create the graph based on user input.

7. It then calls the `DFS()` function to perform Depth First Search on the original graph.

8. It creates a reverse matrix using the `reverseGraph()` function.

9. It calls the `DFSUtil()` function to perform Depth First Search on the reversed graph.

10. The program terminates.*/