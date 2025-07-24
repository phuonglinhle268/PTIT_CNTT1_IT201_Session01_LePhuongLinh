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

void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

//in do thi
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ",i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}
//0: 1 0
//1: 0 3
//2:
//3: 0 1

//duyet do thi DFS
void DFSUtil(Graph* graph, int src, int* visited) {
    //danh sau src da dc duyet qua
    visited[src] = 1;
    //in dinh src ra
    printf("%d ", src);
    //sdung vong lap de ktra tat ca duong di tu dinh src
    for (int i = 0; i < graph->V; i++) {
        //ktra co duong den dinh tiep theo
           //dinh do chua tung dc duyet
        if (graph->adjMatrix[src][i] == 1 && visited[i] == 0) {
            //goi lai ham voi dinh tiep theo duoc duyet
            DFSUtil(graph, i, visited);
        }
    }
}
void DFS(Graph* graph, int src) {
    //khoi tao mang visited
    int* visited = (int *)calloc(graph->V,sizeof(int));
    //in ra thong bao
    printf("DFS tu dinh %d: ",src);
    //goi ham
    DFSUtil(graph, src, visited);
    //giai phong mang visited
    free(visited);
}

//duyet do thi BFS
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
}Queue;
Queue *createQueue(int capacity) {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enQueue(Queue* queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue -> rear++;
    queue->arr[queue->rear] = value;
}
int isQueueEmpty(Queue* queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}
int deQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
       return -1;
    }
    return queue->arr[queue->front++];
}
void BFS(Graph* graph, int src) {
    Queue* queue = createQueue(graph->V);
    int* visited = (int *)calloc(graph->V,sizeof(int));
    visited[src] = 1;
    enQueue(queue, src);
    printf("BFS tu dinh %d: ",src);
    while (!isQueueEmpty(queue)) {
        int currentNode = deQueue(queue);
        printf("%d ", currentNode);
        for (int i = 0; i < graph->V; i++) {
            if (graph->adjMatrix[currentNode][i] == 1 && visited[i] == 0) {
                enQueue(queue, i);
                visited[i] = 1;
            }
        }
    }
    free(visited);
    free(queue->arr);
    free(queue);
}
int main() {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);  // gtri se nam trong cot-canh t/ung
    addEdge(graph, 1, 3);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 2);
    printMatrix(graph);
    printGraph(graph);
    DFS(graph, 0);
    printf("\n");
    BFS(graph, 0);
}

