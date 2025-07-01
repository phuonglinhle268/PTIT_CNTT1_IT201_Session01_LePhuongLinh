#include <stdio.h>

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

        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        printf("Mang sau: ");
        for (int i=0; i<n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}
//Do phuc tap thoi gian: O(n)
//Do phuc tap khong gian: O(1)