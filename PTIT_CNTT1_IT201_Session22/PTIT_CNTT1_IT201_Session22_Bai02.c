#include <stdio.h>
#include <stdlib.h>


 typedef struct Graph {
     int V;
     int** adjList;
 }Graph;


Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph -> V = V;
    graph -> adjList = (int**)malloc(V * sizeof(int*));
    for (int i=0; i<V; i++) {
        graph -> adjList[i] = (int*)calloc(V, sizeof(int));
    }
    return graph;
}
void addEdge(Graph* graph, int firstNode, int secondNode) {
    graph -> adjList[firstNode][secondNode] = 1;
    graph -> adjList[secondNode][firstNode] = 1;
}
void printGraph(Graph* graph) {
    for (int i=0; i<graph->V; i++) {
        for (int j=0; j<graph->V; j++) {
            printf("%d ", graph -> adjList[i][j]);
        }
        printf("\n");
    }
}
void change(Graph* graph) {
    for (int i=0; i<graph->V; i++) {
        printf("%d: ", i);
        for (int j=0; j<graph->V; j++) {
            if (graph -> adjList[i][j] == 1) {
                printf("%d ", j);
            }
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
    change(graph);
}

