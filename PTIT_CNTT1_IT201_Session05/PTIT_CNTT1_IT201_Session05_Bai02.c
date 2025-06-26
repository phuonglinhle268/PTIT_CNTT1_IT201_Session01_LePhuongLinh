#include <stdio.h>

int sumNumber(int n) {
    if (n == 1) {
        return 1;
    }
    return n+sumNumber(n-1);
}
int main() {
    int n;
    printf("Nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    if (n > 0) {
        int sum = sumNumber(n);
        printf("Tong: %d", sum);
    }else {
        printf("Gia tri phai lon hon 0");
    }
    return 0;
}