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
    return graph;
}
void addEdge(Graph* graph, int firstNode, int secondNode) {
    if (firstNode >=0 && firstNode < graph->V && secondNode >= 0 && secondNode < graph -> V) {
        graph -> adjMatrix[firstNode][secondNode] = 1;
        graph -> adjMatrix[secondNode][firstNode] = 1;
    }
}
int count(Graph* graph) {
    int count = 0;
    for (int i=0; i<graph->V; i++) {
        for (int j=i+1; j<graph->V; j++) {
            if (graph -> adjMatrix[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    int n;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    if (n<=0 || n>=100) {
        printf("So dinh khong hop le\n");
        return 0;
    }
    Graph* graph = createGraph(n);
    printf("Nhap ma tran ke:\n", n, n);
    for (int i=0; i<n; i++) {
        graph -> adjMatrix[i] = (int*)malloc(n * sizeof(int));
        for (int j=0; j<n; j++) {
            scanf("%d", &graph -> adjMatrix[i][j]);
        }
    }
    printf("So canh: %d", count(graph));
    return 0;
}
