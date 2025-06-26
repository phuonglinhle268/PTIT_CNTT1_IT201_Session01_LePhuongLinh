#include <stdio.h>

int sumNumber(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n-1] + sumNumber(arr, n-1);
}

int main() {
    int n;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    if (n >0) {
        int arr[n];
        for (int i =0; i < n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        int sum = sumNumber(arr, n);
        printf("Tong mang: %d", sum);
    }else {
        printf("So luong phan tu phai lon hon 0");
    }
    return 0;
}