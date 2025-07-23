#include <stdio.h>
#define SIZE 3

void addEdge(int graph[SIZE][SIZE], int startNode, int endNode) {
    startNode--;
    endNode--;
    graph[startNode][endNode] = 1;
}
void printGraph(int graph[SIZE][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[SIZE][SIZE] = {{0}};
    addEdge(graph, 2, 3);
    printGraph(graph);
    return 0;
}