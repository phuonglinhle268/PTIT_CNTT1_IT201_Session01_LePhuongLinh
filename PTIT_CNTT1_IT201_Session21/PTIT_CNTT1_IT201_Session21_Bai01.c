#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode) {
     firstNode--;
     secondNode--;  //graph[1[[2] dang dc hieu la node 2-3, phai tru di de tro ve 0-based, index 0-1
    //tao canh tu node1
    //khi can nhap tu dinh 1 -> SIZE
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
    int graph[SIZE][SIZE] = {{0}};
    printGraph(graph);
    addEdge(graph, 1, 2);
    printf("----------------------\n");
    printGraph(graph);
    return 0;
}