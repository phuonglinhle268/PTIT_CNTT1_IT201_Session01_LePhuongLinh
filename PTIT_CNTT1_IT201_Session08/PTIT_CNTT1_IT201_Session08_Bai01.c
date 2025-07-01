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
        int value;
        printf("Search = ");
        scanf("%d", &value);
        for (int i=0; i<n; i++) {
            if (arr[i] == value) {
                printf("Vi tri thu %d\n", i+1);
                return 0;
            }
        }
        printf("Khong ton tai phan tu");
    } else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}
//Do phuc tap thoi gian: O(n)
//Do phuc tap khong gian: O(1)