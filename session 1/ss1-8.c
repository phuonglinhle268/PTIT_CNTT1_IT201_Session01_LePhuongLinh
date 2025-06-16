#include <stdio.h>
int mostNumber(int arr[], int n) {
    int checkTime = arr[0];
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxTime) {
            maxTime = count;
            checkTime = arr[i];
        }
    }
    return checkTime;
}
int main() {
    int n;
    printf("Nhan so luong phan tu trong mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhan phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Phan tu xuat hien nhieu nhat la: %d\n", mostNumber(arr, n));
    return 0;
}
//độ phức tạp thời gian: O(n^2)
//độ phức tạp không gian: O(1)