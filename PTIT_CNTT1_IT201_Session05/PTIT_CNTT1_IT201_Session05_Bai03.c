#include <stdio.h>

int giaiThua(int n) {
    if (n == 1) {
        return 1;
    }
    return n*giaiThua(n-1);
}

int main() {
    int n;
    printf("Nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    if (n > 0) {
        int result = giaiThua(n);
        printf("Luy thua: %d", result);
    }else {
        printf("Gia tri phai lon hon 0");
    }
    return 0;
}
