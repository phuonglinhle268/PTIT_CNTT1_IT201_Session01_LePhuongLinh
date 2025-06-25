#include <stdio.h>

int main() {
    int n, value;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    int arr[n];
    if (n>0) {
       for (int i = 0; i < n; i++) {
           printf("Nhap phan tu thu %d: ", i+1);
           scanf("%d", &arr[i]);
       }
        printf("Nhap phan tu can tim: ");
        scanf("%d", &value);
        for (int i = 0; i < n; i++) {
            if (arr[i] == value) {
                printf("Chi so trong mang: %d", i);
                return 0;
            }
        }
        printf("Khong tim thay gia tri");
        return -1;
    } else {
        printf("So luong phan tu phai lon hon 0");
    }
    return 0;
}
