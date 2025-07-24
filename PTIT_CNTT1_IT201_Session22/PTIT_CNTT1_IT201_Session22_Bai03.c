#include <stdio.h>
#include <stdlib.h>


 typedef struct Graph {
     int V;
     int** adjMatrix;
 }Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    //cap phat bo nho cho mang 2 chieu
    graph->adjMatrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        //cap phat cho tung mang con ben trong
        graph->adjMatrix[i] = (int *)calloc(V ,sizeof(int));
    }
    return graph;
}
void addEdge(Graph* graph, int firstNode, int secondNode) {
    graph->adjMatrix[firstNode][secondNode] = 1;
    graph->adjMatrix[secondNode][firstNode] = 1;
}
void change(Graph* graph) {
    for (int i=0; i<graph->V; i++) {
        printf("%d: ", i);
        for (int j=0; j<graph->V; j++) {
            if (graph -> adjMatrix[i][j] == 1) {
                printf("%d -> ", j);
            }
        }
        printf("NULL\n");
    }
}
int main() {
    int n, firstNode, secondNode;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("So dinh khong hop le\n");
        return 0;
    }
    Graph* graph = createGraph(n);
    printf("Nhap canh: ");
    for (int i=0; i<n; i++) {
        graph -> adjMatrix[i] = (int*)malloc(n*sizeof(int));
        for (int j=0; j<n; j++) {
            scanf("%d", &graph -> adjMatrix[i][j]);
        }
    }
    printf("---------------------\n");
    change(graph);
}

