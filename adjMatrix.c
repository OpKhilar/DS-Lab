#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure to represent a graph
typedef struct {
    int vertices;
    int edges;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int directed;  // 0 for undirected, 1 for directed
} Graph;

// Function to initialize a graph
Graph* initializeGraph(int vertices, int isDirected) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = 0;
    graph->directed = isDirected;
    
    // Initialize adjacency matrix with 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v, int weight) {
    // Validate vertices
    if (u < 0 || u >= graph->vertices || v < 0 || v >= graph->vertices) {
        printf("Invalid edge: (%d, %d)\n", u, v);
        return;
    }
    
    // Add edge from u to v
    graph->adj[u][v] = weight;
    
    // If undirected, add edge from v to u
    if (!graph->directed) {
        graph->adj[v][u] = weight;
    }
    
    graph->edges++;
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int u, int v) {
    if (u < 0 || u >= graph->vertices || v < 0 || v >= graph->vertices) {
        printf("Invalid edge: (%d, %d)\n", u, v);
        return;
    }
    
    if (graph->adj[u][v] != 0) {
        graph->adj[u][v] = 0;
        
        if (!graph->directed) {
            graph->adj[v][u] = 0;
        }
        
        graph->edges--;
    }
}

// Function to display the adjacency matrix
void displayGraph(Graph* graph) {
    printf("\n=== Adjacency Matrix ===\n");
    printf("Graph Type: %s\n", graph->directed ? "Directed" : "Undirected");
    printf("Vertices: %d, Edges: %d\n\n", graph->vertices, graph->edges);
    
    // Print column headers
    printf("    ");
    for (int j = 0; j < graph->vertices; j++) {
        printf("%d   ", j);
    }
    printf("\n");
    
    // Print matrix
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d   ", i);
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d   ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if edge exists
int hasEdge(Graph* graph, int u, int v) {
    if (u < 0 || u >= graph->vertices || v < 0 || v >= graph->vertices) {
        return 0;
    }
    return graph->adj[u][v] != 0;
}

// Function to get the degree of a vertex (for undirected graphs)
int getDegree(Graph* graph, int vertex) {
    if (vertex < 0 || vertex >= graph->vertices) {
        return -1;
    }
    
    int degree = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] != 0) {
            degree++;
        }
    }
    return degree;
}

// Function to display neighbors of a vertex
void displayNeighbors(Graph* graph, int vertex) {
    if (vertex < 0 || vertex >= graph->vertices) {
        printf("Invalid vertex: %d\n", vertex);
        return;
    }
    
    printf("Neighbors of vertex %d: ", vertex);
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to free the graph
void freeGraph(Graph* graph) {
    free(graph);
}

// Main function demonstrating the graph operations
int main() {
    printf("===== GRAPH USING ADJACENCY MATRIX =====\n");
    
    // Create an undirected graph with 5 vertices
    int vertices = 5;
    Graph* graph = initializeGraph(vertices, 0);  // 0 = undirected
    
    printf("\nAdding edges...\n");
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 4, 1);
    
    // Display the graph
    displayGraph(graph);
    
    // Display neighbors of each vertex
    printf("\n=== Neighbors of Each Vertex ===\n");
    for (int i = 0; i < vertices; i++) {
        displayNeighbors(graph, i);
        printf("Degree of vertex %d: %d\n", i, getDegree(graph, i));
    }
    
    // Check if specific edges exist
    printf("\n=== Edge Existence Check ===\n");
    printf("Edge (0, 1) exists: %s\n", hasEdge(graph, 0, 1) ? "Yes" : "No");
    printf("Edge (0, 2) exists: %s\n", hasEdge(graph, 0, 2) ? "Yes" : "No");
    printf("Edge (2, 3) exists: %s\n", hasEdge(graph, 2, 3) ? "Yes" : "No");
    
    // Remove an edge
    printf("\n=== Removing Edge (1, 3) ===\n");
    removeEdge(graph, 1, 3);
    displayGraph(graph);
    
    // Free the graph
    freeGraph(graph);
    
    printf("\n===== DIRECTED GRAPH EXAMPLE =====\n");
    
    // Create a directed graph with 4 vertices
    Graph* directedGraph = initializeGraph(4, 1);  // 1 = directed
    
    printf("\nAdding edges to directed graph...\n");
    addEdge(directedGraph, 0, 1, 1);
    addEdge(directedGraph, 0, 2, 1);
    addEdge(directedGraph, 1, 2, 1);
    addEdge(directedGraph, 1, 3, 1);
    addEdge(directedGraph, 2, 3, 1);
    
    displayGraph(directedGraph);
    
    printf("\n=== Neighbors (Outgoing edges) ===\n");
    for (int i = 0; i < 4; i++) {
        displayNeighbors(directedGraph, i);
    }
    
    freeGraph(directedGraph);
    
    return 0;
}