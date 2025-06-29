#include <stdio.h>

int nhiPhan(int n) {
    if (n == 0) {
        return;
    }
    nhiPhan(n/2);
    printf("%d", n%2); //lấy phần dư->bit nhị phan
}

int main() {
    int n;
    printf("Nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    if (n>0) {
        printf("Dang nhi phan: ", n);
        nhiPhan(n);
    }else {
        printf("Gia tri phai lon hon 0");
    }
    return 0;
}

