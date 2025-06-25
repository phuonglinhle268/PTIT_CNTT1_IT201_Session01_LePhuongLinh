#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    if (n>0) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        int min = arr[0];
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
                index = i;
            }
        }
        printf("So nho nhat trong mang co chi so: %d", index);
    }else {
        printf("So luong phan tu phai lon hon 0");
    }
}
