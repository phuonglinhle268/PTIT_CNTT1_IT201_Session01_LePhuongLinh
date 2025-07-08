#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int cap;
} Stack;

Stack* createStack(int cap) {
    Stack* stack =(Stack*)malloc(sizeof(Stack));
    stack -> arr = (int*)malloc(cap* sizeof(int));
    stack -> top = -1;
    stack -> cap = cap;
    return stack;
}
int isFull(Stack* stack) {
    if (stack -> top >= stack -> cap - 1) {
        return 1;
    }
    return 0;
}
int isEmpty(Stack* stack) {
    if (stack -> top == -1) {
        return 1;
    }
    return 0;
}
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep da day");
        return;
    }
    stack -> top++;
    stack -> arr[stack -> top] = value;

}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong");
        return -1;
    }
    int value = stack -> arr[stack -> top];
    stack -> top--;
    return value;
}
void reverse(int arr[], int n) {
    Stack* stack = createStack(n);
    for (int i =0; i<n; i++) {
        push(stack, arr[i]);
    }
    for (int i=0; i<n; i++) {
        arr[i] = pop(stack);
    }
    free(stack -> arr);
    free(stack);
}
void printStack(int arr[], int n) {
    for (int i=0; i <n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void freeStack(Stack* stack) {
    free(stack ->arr);
    free(stack);
}
int main() {
    int n = 5;
    int arr[5];
    Stack* stack = createStack(n);
    printf("Ngan xep voi toi da %d phan tu\n", n);
    for (int i =0; i< n; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    reverse(arr, n);
    printf("\nMang sau dao nguoc: ");
    printStack(arr,n);

    freeStack(stack);
}