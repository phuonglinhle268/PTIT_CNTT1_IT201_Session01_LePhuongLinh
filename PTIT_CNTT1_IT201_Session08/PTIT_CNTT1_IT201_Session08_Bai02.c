#include <stdio.h>

void sortNumber(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j <n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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
        sortNumber(arr, n);
        int value;
        printf("Search = ");
        scanf("%d", &value);
        int result = binarySearch(arr, n, value);
        if (result != -1) {
            printf("Vi tri thu %d\n", result + 1);
        } else {
            printf("Khong ton tai phan tu");
        }
    }else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}
//Do phuc tap khong gian:O(1)
//Do phuc tap thoi gian: O(n^2)
