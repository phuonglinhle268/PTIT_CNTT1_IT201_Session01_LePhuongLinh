#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i=0; i<n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j=0; j<n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i=0;
    int j=0;
    int k = left;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }else {
            arr[k++] = R[j++];
        }
    }
    while (i<n1) {
        arr[k++] = L[i++];
    }
    while (j<n2) {
        arr[k++] = R[j++];
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
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
        mergeSort(arr, 0, n-1);
        printf("Mang sau: ");
        for (int i=0; i<n; i++) {
            printf("%d",arr[i]);
        }
        printf("\n");
    } else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}