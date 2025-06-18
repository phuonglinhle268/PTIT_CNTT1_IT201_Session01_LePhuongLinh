#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Nhap so luong phan tu co trong mang (0<n<=100): ");
    scanf("%d", &n);

    if (n>0 && n<=100) {
        int *arr = (int*)malloc(n*sizeof(int));
        if (arr==NULL) {
            printf("Khong the cap phat bo nho");
            return 1;
        }
        for (i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ",i+1);
            scanf("%d", &arr[i]);
        }
        for (i = 0; i < n/2; i++) {
            int temp = arr[i];
            arr[i] = arr[n-1-i];
            arr[n-1-i] = temp;
        }
        printf("Mang sau khi dao nguoc: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("So luong phan tu khong hop le\n");
    }
    return 0;
}