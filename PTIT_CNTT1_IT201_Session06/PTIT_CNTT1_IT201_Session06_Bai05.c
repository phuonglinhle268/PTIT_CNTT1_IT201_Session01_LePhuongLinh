#include <stdio.h>

int maxNumber(int arr[], int n) {
    if (n==1) {
        return arr[0];
    }
    int max = maxNumber(arr, n-1);
    if (arr[n-1] > max) {
        return arr[n-1];
    }
    return max;
}

int minNumber(int arr[], int n) {
    if (n==1) {
        return arr[0];
    }
    int min = minNumber(arr, n-1);
    if (arr[n-1] < min) {
        return arr[n-1];
    }
    return min;
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n>0) {
        int arr[n];
        for (int i=0; i<n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        int lonNhat = maxNumber(arr, n);
        int nhoNhat = minNumber(arr, n);

        printf("So lon nhat:%d \n", lonNhat);
        printf("So nho nhat:%d ", nhoNhat);
    }else {
        printf("Gia tri phai lon hon 0");
    }
    return 0;
}