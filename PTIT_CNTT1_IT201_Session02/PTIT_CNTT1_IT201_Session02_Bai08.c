#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu co trong mang: ");
    scanf("%d", &n);
    if (n > 0) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Khong the cap phan bo nho");
            return 1;
        }
        for (int i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
        int found = 0;
        printf("Cac phan tu lon hon cac phan tu dung sau: ");
        for (int i = 0; i < n; i++) {
            int checkNum = 1;
            for (int j = i+1; j < n; j++) {
                if (arr[i] <= arr[j]) {
                    checkNum = 0;
                    break;
                }
            }
            if (checkNum) {
                printf("%d ", arr[i]);
                found = 1;
            }
        }
        if (!found) {
            printf("Khong co phan tu thoa man");
        }
    } else {
        printf("So luong phan tu phai lon hon 0");
    }
    return 0;
}