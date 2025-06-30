#include <stdio.h>

int merge(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;

    return i+1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = merge(arr, left, right);
        quickSort(arr, left, pi-1);
        quickSort(arr, pi+1, right);
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
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
        printf("Before: ");
        printArray(arr, n);

        quickSort(arr, 0, n-1);

        printf("After: ");
        printArray(arr, n);

        return 0;
    } else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}