#include <stdio.h>

#define MAX_VERTICES 10

void breadthFirstTraversal(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start) {
	int queue[MAX_VERTICES];
	int visited[MAX_VERTICES] = {0};
	int front = 0;
	int rear = 0;

	visited[start] = 1;
	queue[rear++] = start;

	printf("Breadth-first traversal: ");
	while (front < rear) {
		int vertex = queue[front++];
		printf("%d ", vertex);

		for (int neighbor = 0; neighbor < vertices; neighbor++) {
			if (graph[vertex][neighbor] != 0 && !visited[neighbor]) {
				visited[neighbor] = 1;
				queue[rear++] = neighbor;
			}
		}
	}
	printf("\n");
}

int main(void) {
	int graph[MAX_VERTICES][MAX_VERTICES] = {0};
	int vertices;
	int start;

	printf("Enter the number of vertices (1-%d): ", MAX_VERTICES);
	if (scanf("%d", &vertices) != 1 || vertices < 1 || vertices > MAX_VERTICES) {
		printf("Invalid number of vertices.\n");
		return 1;
	}

	printf("Enter the adjacency matrix (%d x %d):\n", vertices, vertices);
	for (int row = 0; row < vertices; row++) {
		for (int column = 0; column < vertices; column++) {
			if (scanf("%d", &graph[row][column]) != 1) {
				printf("Invalid adjacency matrix.\n");
				return 1;
			}
		}
	}

	printf("Enter the starting vertex (0-%d): ", vertices - 1);
	if (scanf("%d", &start) != 1 || start < 0 || start >= vertices) {
		printf("Invalid starting vertex.\n");
		return 1;
	}

	breadthFirstTraversal(graph, vertices, start);
	return 0;
}
