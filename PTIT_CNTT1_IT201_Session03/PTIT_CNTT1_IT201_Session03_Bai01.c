#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Nhap so luong phan tu co trong mang (0<n<1000): ");
    scanf("%d", &n);

    if (n<=0) {
        printf("So luong phan tu phai lon hon 0");
    }else {
        int *arr = malloc(sizeof(int) * n);
        if (arr==NULL) {
            printf("Khong cap phat duoc bo nho");
            return 1;
        }
        for (i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        printf("Cac phan tu co trong mang la: ");
        for (i = 0; i < n; i++) {
            printf("%d ",arr[i]);
        }
        free(arr);
    }
    return 0;
}