#include <stdio.h>
#define SIZE 3

void addEdge(int graph[SIZE][SIZE], int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}
void printGraph(int graph[SIZE][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[SIZE][SIZE] = {{0}};
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    printGraph(graph);
    return 0;
}
