#include <stdio.h>

int sum(int n) {
    if (n==0) {
        return 0;
    }
    return (n%10) + sum(n/10);
}

int main() {
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n>0) {
        int result = sum(n);
        printf("Tong cac chu so: %d", result);
    }else {
        printf("Gia tri phai lon hon 0");
    }
    return 0;
}
