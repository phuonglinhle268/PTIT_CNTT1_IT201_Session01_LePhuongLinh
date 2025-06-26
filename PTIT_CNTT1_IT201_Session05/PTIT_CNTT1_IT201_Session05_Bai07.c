#include <stdio.h>

int number(int a) {
    if (a == 0) {
        return 0;
    }
    if (a == 1) {
        return 1;
    }
    return number(a-1) + number(a-2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    if (n>0) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = number(i);
        }
        printf("%d so fibonacci dau tien: \n", n);
        for (int i=0; i<n; i++) {
            printf("%d\n", arr[i]);
        }
    }else {
        printf("Gia tri phai lon hon 0");
    }
    return 0;
}