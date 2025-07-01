#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int quick(int arr[], int low, int high) {
    int pivot = arr[high];
    int i=low-1;
    for (int j=low; j<high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = quick(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
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
        quickSort(arr, 0, n-1);
        printf("Mang sau: ");
        for (int i=0; i<n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    } else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}
