#include <stdio.h>
#include <stdbool.h>
bool dupNumber(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap phan tu tu 0-1000: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (dupNumber(arr, n)) {
        printf("Co phan tu trung lap\n");
    } else {
        printf("Khong co phan tu trung lap\n");
    }
    return 0;
}
//Độ phức tạp thời gian: O(n^2)
//Độ phức tạp không gian: O(1)

// //Cách 2:
void checkNumber(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
bool numberDuplicate(int arr[], int n) {
    checkNumber(arr, n);
    for (int i = 0; i < n-1; i++) {
        if (arr[i] == arr[i+1]) {
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap phan tu tu 0-1000: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (numberDuplicate(arr, n)) {
        printf("Co phan tu trung lap\n");
    } else {
        printf("Khong co phan tu trung lap\n");
    }
    return 0;
}
//Độ phức tạp thời gian: O(n^2)
//Độ phức tạp không gian: O(1)