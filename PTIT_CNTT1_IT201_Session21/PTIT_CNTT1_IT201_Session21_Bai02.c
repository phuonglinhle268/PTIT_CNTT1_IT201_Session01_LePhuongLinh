#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode) {
    //tao canh tu 0
    if (firstNode >= 0 && firstNode < SIZE && secondNode >= 0 && secondNode < SIZE) {
        graph[firstNode][secondNode] = 1;
        graph[secondNode][firstNode] = 1;
    }
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
    int graph[SIZE][SIZE] = {{0}};  // khoi tao ma tran 0
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    return 0;
}