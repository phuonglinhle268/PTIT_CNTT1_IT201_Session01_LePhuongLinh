#include <stdio.h>
#include <stdlib.h>

//cau truc do thi
typedef struct Graph {
    int V;
    int **adjMatrix;
}Graph;

//xdung ham khoi tao do thi
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
//xay dung ham thiet lap canh
void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}
//ham in do thi
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);  // gtri se nam trong cot-canh t/ung
    printGraph(graph);
}

