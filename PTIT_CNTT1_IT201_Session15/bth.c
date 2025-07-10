#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;  //chi so ptu dau hang
    int rear;  //chi so ptu cuoi
    int capacity;   //gioi han hang doi
} Queue;

//ham khoi tao hang doi
Queue* createQueue(int capacity) {
    //cap phat bo nho
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    //gan cac gtri
    queue -> front = 0;
    queue -> rear = -1;
    queue -> capacity = capacity;
    queue -> arr = (int*)malloc(sizeof(int) * capacity);
    //tra ve dia chi hang doi dc khoi tao
    return queue;
}
//xay dung ham them phan tu
void enQueue(Queue* queue, int value) {
    //kiem tra hang doi day
    if (queue -> rear < queue -> capacity - 1) {
        //tang chi so ptu cuoi hang doi
        queue -> rear++;
        //gan gtri cho ptu cuoi hang doi
        queue -> arr[queue -> rear] = value;
    }
}
//ktra hang doi trong
int isEmpty(Queue* queue) {
    if (queue -> rear < queue -> front) {
        return 1;
    }
    return 0;
}
//xoa ptu dau hang doi
void deQueue(Queue* queue) {
    //ktra hang doi trong
    if (!isEmpty(queue)) {

    }
    //tang chi so ptu dau tien
}