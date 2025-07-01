#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int key = arr[i];
        int j=i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int linearSearch(int arr[], int n, int value) {
    for (int i=0; i<n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int value) {
    int low =0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value){
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    if (n>0 && n<1000) {
        int arr[n];
        for (int i=0; i<n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        printf("Mang ban dau: ");
        for (int i=0; i<n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        insertionSort(arr, n);
        printf("Mang sau: ");
        for (int i=0; i<n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");

        int value;
        printf("\nSearch: ");
        scanf("%d", &value);
        int linear = linearSearch(arr, n, value);
        if (linear != -1) {
            printf("Tim kiem tuyen tinh: Vi tri %d\n", linear+1);
        } else {
            printf("Khong tim thay phan tu");
        }

        int binary = binarySearch(arr, n, value);
        if (binary != -1) {
            printf("Tim kiem nhi phan: Vi tri %d\n", binary+1);
        } else {
            printf("Khong tim thay phan tu");
        }
    }else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}
