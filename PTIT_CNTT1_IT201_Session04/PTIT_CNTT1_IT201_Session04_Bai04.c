#include <stdio.h>

int main() {
    int n, value;
    int index=-1;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    if (n>0) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        printf("Nhap gia tri bat ki: ");
        scanf("%d", &value);
        for (int i = 0; i < n; i++) {
            if (arr[i] == value) {
                index = i;
            }
        }
        if (index != -1) {
            printf("Chi so cua phan tu cuoi cung la: %d", index);
        }else {
            printf("Khong tim thay phan tu");
        }
    } else {
        printf("So luong phan tu phai lon hon 0");
    }
    return 0;
}