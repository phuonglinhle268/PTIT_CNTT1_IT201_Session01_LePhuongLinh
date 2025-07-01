#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    if (n>0 && n<1000) {
        int arr[n];
        for (int i =0; i<n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        printf("Mang ban dau: ");
        for (int i=0; i<n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");

        for (int i=0; i<n-1; i++) {
            int min_index = i;
            for (int j=i+1; j<n; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                int temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
            }
        }
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
