#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Question {
    int id;
    char content[100];
} Question;

typedef struct Stack {
    Question* questions;
    int top;
    int capacity;
} Stack;

typedef struct Queue {
    Question* questions;
    int front;
    int rear;
    int capacity;
} Queue;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    return stack;
}
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue -> capacity = capacity;
    queue -> front = 0;
    queue -> rear = -1;
    return queue;
}
void push(Stack* stack, Question question) {
    if (stack -> top == stack -> capacity -1) {
        printf("Stack da day\n");
        return;
    }
    stack -> top++;
    stack -> questions[stack -> top] = question;
}
Question pop(Stack* stack) {
    if (stack -> top == -1) {
        printf("Stack rong\n");
        return;
    }
    stack -> top--;
    return stack -> questions[stack -> top];
}
void enqueue(Queue* queue, Question question) {
    if (queue -> rear == queue -> capacity - 1) {
        printf("Queue da day\n");
        return;
    }
    queue -> rear++;
    queue -> questions[queue -> rear] = question;
}
void displayQueue(Queue* queue) {
    if (queue -> rear == queue -> capacity - 1) {
        printf("Queue rong\n");
        return;
    }
    for (int i = queue -> front; i <= queue -> rear; i++) {
        printf("%d ", queue -> questions[i].id);
        printf("%s ", queue -> questions[i].content);
    }
}
int isEmpty(Stack* stack) {
    if (stack -> top == -1) {
        return 1;
    }
    return 0;
}
int main() {
    int choice;
    Stack* practiceStack = createStack(10);
    Stack* redoStack = createStack(10);
    Queue* fullHistory = createQueue(10);
    do {
        printf("\n-----INTERVIEW MANAGER-----\n");
        printf("1. Practice\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. History\n");
        printf("5. Exit\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Question question;
                printf("Nhap ID cho cau hoi: ");
                scanf("%d", question.id);
                getchar();
                printf("nhap content: ");
                fgets(question.content, sizeof(question.content), stdin);
                question.content[strcspn(question.content, "\n")] = '\0';
                push(practiceStack, question);
                enqueue(fullHistory, question);
                redoStack = createStack(10);
                break;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("EXIT\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 5);
    return 0;
}

