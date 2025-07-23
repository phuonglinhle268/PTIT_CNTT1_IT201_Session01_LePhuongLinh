#include <stdio.h>
#include <stdlib.h>

 typedef struct Node {
     int data;
     struct Node* next;
 }Node;

typedef struct Graph {
    int V;
    Node** adjMatrix;
}Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph -> V = V;
    graph -> adjMatrix = (Node**)malloc(V*sizeof(Node*));
    for (int i=0; i<V; i++) {
        graph -> adjMatrix[i] = NULL;
    }
    return graph;
}
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
void addEdge(Graph* graph, int startNode, int endNode) {
    Node* newNode = createNode(endNode);
    newNode -> next = graph -> adjMatrix[startNode];
    graph -> adjMatrix[startNode] = newNode;

    newNode = createNode(startNode);
    newNode -> next = graph -> adjMatrix[endNode];
    graph -> adjMatrix[endNode] = newNode;
}
void printGraph(Graph* graph) {
    for (int i=0; i< graph->V; i++) {
        printf("%d -> ", i);
        Node* temp = graph -> adjMatrix[i];
        while (temp != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
}
int main() {

    int V = 3;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    printGraph(graph);
    return 0;
}

// do thi in ra
//dinh 0 co canh -> 1
//dinh 1 co canh -> 2 va 0
//dinh 2 co canh -> 1
//   0 1 2
//   : : :
//0: 0 1 0
//1: 1 0 1
//2: 0 1 0