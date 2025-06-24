#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, x;
    int count=0;

    printf("Nhap so phan tu co trong mang (0<n<=100): ");
    scanf("%d", &n);

    if (n>0 && n<=100) {
        int *arr = (int*)malloc(n*sizeof(int));
        if (arr==NULL) {
            printf("Khong the cap phat bo nho");
            return 1;
        }
        for (i = 0; i < n; i++) {
            printf("Nhap so thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        printf("Nhap so muon biet so lan xuat hien: ");
        scanf("%d", &x);
        for (i = 0; i < n; i++) {
            if (arr[i] == x) {
                count++;
            }
        }
        printf("So %d xuat hien %d trong mang\n", x, count);
    } else {
        printf("So luong khong hop le");
    }
    return 0;
}
