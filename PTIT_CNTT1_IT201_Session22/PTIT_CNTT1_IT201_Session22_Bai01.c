#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int** adjMatrix;
}Graph;
Graph* createGraph(int V) {
     Graph* graph = (Graph*)malloc(sizeof(Graph));
     graph -> V = V;
     graph -> adjMatrix = (int**)malloc(V * sizeof(int*));
     for (int i=0; i<V; i++) {
         graph -> adjMatrix[i] = (int*)calloc(V, sizeof(int));
     }
     return graph;
 }
void addEdge(Graph* graph, int firstNode, int secondNode) {
    if (firstNode >=0 && firstNode < graph->V && secondNode >= 0 && secondNode < graph -> V) {
        graph -> adjMatrix[firstNode][secondNode] = 1;
        graph -> adjMatrix[secondNode][firstNode] = 1;
    }
}
void printGraph(Graph* graph) {
    for (int i=0; i<graph->V; i++) {
        for (int j=0; j<graph->V; j++) {
            printf("%d ", graph -> adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, firstNode, secondNode;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    Graph* graph = createGraph(n);
    printf("Nhap canh: ");
    while (scanf("%d %d", &firstNode, &secondNode)==2) {

        addEdge(graph, firstNode, secondNode);
    }
    printf("---------------------\n");
    printGraph(graph);
}
