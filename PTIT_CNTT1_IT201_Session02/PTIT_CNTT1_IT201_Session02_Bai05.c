#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, pos;

    printf("Nhap so luong phan tu co trong mang (0<n<=100): ");
    scanf("%d",&n);

    if (n>0 && n<=100) {
        int *arr = malloc(sizeof(int) * n);
        if (arr==NULL) {
            printf("Khong the cap phan bo nho");
            return 1;
        }
        for (i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        printf("Nhap vi tri muon sua: ", n-1);
        scanf("%d",&pos);
        if (pos>=0 && pos<n) {
            for (i = pos;i<n-1;i++) {
                arr[i] = arr[i+1];
            }
            n--;
            printf("Mang sau khi xoa la: ");
            for (i = 0; i < n; i++) {
                printf("%d ",arr[i]);
            }
        }else {
            printf("Vi tri sua khong hop le");
        }
    }else {
        printf("So luong khong hop le ");
    }
    return 0;
}
