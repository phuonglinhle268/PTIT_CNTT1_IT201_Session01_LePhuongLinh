#include <stdio.h>

int number(int a) {
    if (a==0) {
        return 0;
    }
    if (a==1) {
        return 1;
    }
    return number(a-1)+number(a-2);
}

int daoNguoc(int n) {
    if (n==0) {
        return;
    }
    printf("%d", number(n-1));
    daoNguoc(n-1);
}

int main() {
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n>0) {
        printf("%d phan tu dau tien cua day Fibonacci: ", n);
        daoNguoc(n);
    }else {
        printf("Gia tri phai lon hon 0");
    }
    return 0;
}
