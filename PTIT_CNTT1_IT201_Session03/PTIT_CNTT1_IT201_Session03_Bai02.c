#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Nhap so luong phan tu co trong mang (0<n<1000): ");
    scanf("%d", &n);

    if (n>0 && n<1000) {
        int* arr = (int*)malloc(n*sizeof(int));
        if (arr == NULL) {
            printf("Khong cap phat duoc bo nho");
            return 1;
        }
        for (i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        int maxNumber = arr[0];
        for (i = 0; i < n; i++) {
            if (arr[i] > maxNumber) {
                maxNumber = arr[i];
            }
        }
        printf("So lon nhat trong mang la: %d", maxNumber);
        free(arr);
    } else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}