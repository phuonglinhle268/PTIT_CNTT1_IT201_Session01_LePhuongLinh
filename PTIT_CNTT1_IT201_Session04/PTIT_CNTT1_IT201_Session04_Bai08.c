#include <stdio.h>

int main() {
    int n, value;
    int found = 0;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    if (n>0) {
        int arr[n];
        for (int i =0; i<n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        printf("Nhap gia tri muon tim vi tri: ");
        scanf("%d", &value);
        for (int i=0; i<n; i++) {
            if (arr[i]==value) {
                printf("%d", i);
                found = 1;
            }
        }
        if (!found) {
            printf("Phan tu khong co trong mang");
        }
    }else {
        printf("So luong phan tu phai lon hon 0");
    }
    return 0;
}