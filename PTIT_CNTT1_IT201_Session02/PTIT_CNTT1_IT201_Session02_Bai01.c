#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Nhap so luong phan tu co trong mang (0<n<=100): ");
    scanf("%d", &n);

    if (n>0 && n<=100) {
        int *arr = (int*)malloc(n*sizeof(int));
        for (i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        int maxNumber = arr[0];
        for (i = 0; i < n; i++) {
            if (arr[i] > maxNumber) {
                maxNumber = arr[i];
            }
        }
        printf("Phan tu lon nhat trong mang la: %d\n", maxNumber);
    } else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}