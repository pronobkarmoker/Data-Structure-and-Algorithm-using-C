#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAX_VERTICES 100

struct Stack {
    int items[MAX_VERTICES];
    int top;
};

struct Stack* createStack();
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
bool isEmpty(struct Stack* stack);
int peek(struct Stack* stack);

struct Graph {
    int numVertices;
    int** adjMatrix;
    int* visited;
    int* discoveryTime;
    int* lowTime;
    struct Stack* stack;
};

struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void dfsBridges(struct Graph* graph, int vertex, int parent);
void findBridges(struct Graph* graph);
void dfsBiconnectedComponents(struct Graph* graph, int vertex, int parent);
void findBiconnectedComponents(struct Graph* graph);

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->items[stack->top--];
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->items[stack->top];
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(numVertices, sizeof(int));
    }

    graph->visited = (int*)calloc(numVertices, sizeof(int));
    graph->discoveryTime = (int*)malloc(numVertices * sizeof(int));
    graph->lowTime = (int*)malloc(numVertices * sizeof(int));
    graph->stack = createStack();

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void dfsBridges(struct Graph* graph, int vertex, int parent) {
    static int time = 0;

    graph->visited[vertex] = 1;
    graph->discoveryTime[vertex] = graph->lowTime[vertex] = ++time;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1) {
            if (graph->visited[i] == 0) {
                push(graph->stack, vertex);
                dfsBridges(graph, i, vertex);

                graph->lowTime[vertex] = min(graph->lowTime[vertex], graph->lowTime[i]);

                if (graph->lowTime[i] > graph->discoveryTime[vertex]) {
                    printf("Bridge: %d-%d\n", vertex, i);
                }
            }
            else if (i != parent) {
                graph->lowTime[vertex] = min(graph->lowTime[vertex], graph->discoveryTime[i]);
            }
        }
    }
}

void findBridges(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            dfsBridges(graph, i, -1);
        }
    }
}



int main() {
    int numVertices = 9;
    struct Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 8);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 8);

    printf("Bridges:\n");
    findBridges(graph);



    return 0;
}

/*

1. `#include <stdio.h>`, `#include <stdlib.h>`, and `#include <stdbool.h>`: These lines include the standard input-output, standard library, and boolean headers, respectively, for handling input/output operations, memory management, and using boolean data type.
2. `#define min(a, b) ((a) < (b) ? (a) : (b))`: This line defines a macro `min` that returns the minimum of two values `a` and `b`.
3. `#define MAX_VERTICES 100`: This line defines a constant `MAX_VERTICES` to specify the maximum number of vertices in the graph. You can adjust this value based on your requirements.
4. `struct Stack { ... };`: This block of code defines a structure `Stack` to represent a stack data structure using an array.
5. `struct Graph { ... };`: This block of code defines a structure `Graph` to represent a graph data structure.
6. `struct Stack* createStack();`: This line declares the function prototype for creating a stack.
7. `void push(struct Stack* stack, int item);`: This line declares the function prototype for pushing an item onto the stack.
8. `int pop(struct Stack* stack);`: This line declares the function prototype for popping an item from the stack.
9. `bool isEmpty(struct Stack* stack);`: This line declares the function prototype for checking if the stack is empty.
10. `int peek(struct Stack* stack);`: This line declares the function prototype for getting the top element of the stack without removing it.
11. `struct Graph* createGraph(int numVertices);`: This line declares the function prototype for creating a graph with a specified number of vertices.
12. `void addEdge(struct Graph* graph, int src, int dest);`: This line declares the function prototype for adding an edge between two vertices in the graph.
13. `void dfsBridges(struct Graph* graph, int vertex, int parent);`: This line declares the function prototype for performing depth-first search to find bridges in the graph.
14. `void findBridges(struct Graph* graph);`: This line declares the function prototype for finding and printing the bridges in the graph.
15. `struct Stack* createStack() { ... }`: This block of code defines the `createStack` function that creates and initializes a stack.
16. `void push(struct Stack* stack, int item) { ... }`: This block of code defines the `push` function that pushes an item onto the stack.
17. `int pop(struct Stack* stack) { ... }`: This block of code defines the `pop` function that pops an item from the stack and returns it.
18. `bool isEmpty(struct Stack* stack) { ... }`: This block of code defines the `isEmpty` function that checks if the stack is empty.
19. `int peek(struct Stack* stack) { ... }`: This block of code defines the `peek` function that returns the top element of the stack without removing it.
20. `struct Graph* createGraph(int numVertices) { ... }`: This block of code defines the `createGraph` function that creates a graph with the specified number of vertices and initializes its adjacency matrix, visited array, discovery time array, low time array, and stack.
21. `void addEdge(struct Graph* graph, int src, int dest) { ... }`: This block of code defines the `addEdge` function that adds an edge between two vertices in the graph by updating the adjacency matrix.
22. `void dfsBridges(struct Graph* graph

, int vertex, int parent) { ... }`: This block of code defines the `dfsBridges` function that performs a depth-first search to find bridges in the graph.
23. `void findBridges(struct Graph* graph) { ... }`: This block of code defines the `findBridges` function that initializes the necessary variables and calls `dfsBridges` for each unvisited vertex in the graph to find and print the bridges.
24. `int main() { ... }`: This is the main function where the program execution begins.
25. `int numVertices = 9;`: This line declares and initializes the number of vertices in the graph.
26. `struct Graph* graph = createGraph(numVertices);`: This line creates a graph using the `createGraph` function and assigns it to the `graph` variable.
27. `addEdge(graph, 0, 1);` to `addEdge(graph, 4, 8);`: These lines add edges between vertices in the graph using the `addEdge` function.
28. `printf("Bridges:\n");`: This line prints a header indicating the beginning of the bridge output.
29. `findBridges(graph);`: This line calls the `findBridges` function to find and print the bridges in the graph.
30. `return 0;`: This line indicates the successful execution of the program and returns 0 to the operating system.
*/
