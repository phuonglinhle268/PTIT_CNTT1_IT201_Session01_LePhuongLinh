#include <stdlib.h>
#include <stdio.h>

int main() {
    int m,n, i;
    printf("Nhap so luong ban dau cua mang (0<n<1000): ");
    scanf("%d",&n);
    if (n>0 && n<1000) {
        int *arr = (int*)malloc(n*sizeof(int));
        if (arr==NULL) {
            printf("Khong the cap phat bo nho");
            return 1;
        }
        for (i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        printf("Cac so luong phan tu muon them: ");
        scanf("%d",&m);

        if (m <0) {
            printf("So luong phan tu khong hop le");
            free(arr);
            return 1;
        }

        int *arr1 = (int*)realloc(arr,(n+m)*sizeof(int));
        if (arr1==NULL) {
            printf("Khong the cap phat bo nho");
            free(arr);
            return 1;
        }
        arr1 = arr;
        for (i = 0; i < n+m; i++) {
            printf("Nhap phan tu thu %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        printf("Mang sau khi them la: ");
        for (i = 0; i < n+m; i++) {
            printf("%d ",arr[i]);
        }
        free(arr);
    }
    return 0;
}
