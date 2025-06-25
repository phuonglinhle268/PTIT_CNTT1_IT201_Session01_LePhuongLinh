#include <stdio.h>

void sortNumber(int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int value) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, value;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);

    if (n>0) {
        int arr[n];
        for (int i =0; i<n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        sortNumber(arr, n);
        printf("Mang sau khi sap xep la: ");
        for (int i=0; i<n; i++) {
            printf("%d", arr[i]);
        }
        printf("Nhap gia tri muon tim: ");
        scanf("%d", &value);
        int foundNumber = binarySearch(arr, n, value);
        if (foundNumber != -1) {
            printf("Phan tu co trong mang");
        } else {
            printf("Phan tu khong co trong mang");
        }
    }
    return 0;
}