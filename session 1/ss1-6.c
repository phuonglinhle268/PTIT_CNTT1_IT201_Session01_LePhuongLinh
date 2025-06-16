#include <stdio.h>
int countTimes(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}
int main() {
    int n, x;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap phan tu co trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap phan tu muon biet so lan xuat hien: ");
    scanf("%d", &x);
    printf("So lan xuat hien cua phan tu %d trong mang la: %d",x, countTimes(arr, n, x));
    return 0;
}

//Độ phuc tạp thời gian: O(n)
//Độ phức tạp không gian: O(1)