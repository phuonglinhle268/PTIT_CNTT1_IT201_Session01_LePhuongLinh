#include <stdio.h>
#include <stdlib.h>

//xay dung cau truc du lieu ngan xep
typedef struct Stack {
    int *arr;
    int top;
    int cap;
};
//xay dung ham khoi tao ngan xep
Stack *createStack(int cap) {
    //b1: cap phat bo nho cho ngan xep
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    //b2: gan gtri cho top
    stack -> top = -1;
    //b3: gan gtri cho cap (kich thuoc toi da cua stack)
    stack -> cap = cap;
    //b4: cap phat bo nho
    stack -> arr = (int *)malloc(sizeof(int) * cap);
    //b5: tra ve stack dc khoi tao
    return stack;
}
//xay dung ham ktra stack overflow
int isFull(Stack *stack) {
    //ss top va cap, tra ve kqua
    if (stack -> top == stack -> cap - 1) {
        return 1;
    }
}
//xay dung ham them phan tu vao stack
int push(Stack *stack, int val) {
    //ktra stack overflow va tra ve gtri
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return 0;
    }
    //tien hanh day ptu vao ngan xep
    stack -> top = stack -> top + 1;
    stack -> arr[stack -> top] = val;
}
//xay dung ham kiem tra ngan xep trong
int isEmpty(Stack *stack) {
    if (stack -> top == -1) {
        return 1;
    }
}
//xay dung ham lay ptu ra khoi ngan xep
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return 0;
    }
    stack -> top = stack -> top - 1;
    return stack -> arr[stack -> top + 1];
}

int main() {

}