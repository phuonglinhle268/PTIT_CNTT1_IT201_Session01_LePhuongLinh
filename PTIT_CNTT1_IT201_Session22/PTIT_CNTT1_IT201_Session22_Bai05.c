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
    for (int i = 0; i < V; i++) {
        graph -> adjMatrix[i] = (int*)calloc(V ,sizeof(int));
    }
    return graph;
}
void addEdge(Graph* graph, int u, int v) {
    if (u >=0 && v < graph->V && u >= 0 && v < graph -> V) {
        graph -> adjMatrix[u][v] = 1;
        graph -> adjMatrix[v][u] = 1;
    }
}
int count(Graph* graph, int a) {
    if (a < 0 || a >= graph -> V) {
        return -1;
    }
    int count = 0;
    for (int i=0; i<graph->V; i++) {

            if (graph -> adjMatrix[a][i] == 1) {
                count++;
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
    printf("Nhap cac canh:\n");
    int u,v;
    while (1) {
        scanf("%d %d", &u, &v);
        if (u==-1 && v==-1) {
            break;
        }
        addEdge(graph, u, v);
    }
    int a;
    printf("Nhap dinh can dem: ");
    scanf("%d", &a);
    int result = count(graph, a);
    printf("So dinh lien ke voi %d la: %d\n", a, result);

}

