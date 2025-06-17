#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    if (n > 0) {
        int *arr = (int*)malloc(n*sizeof(int));
        for (int i=0;i<n;i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d",&arr[i]);
        }
        int sumNumber;
        printf("Nhap so nguyen can tim tong: ");
        scanf("%d",&sumNumber);
        int found = 0;
        for (int i=0;i<n-1 && !found;i++) {
            for (int j=i+1;j<n;j++) {
                if (arr[i] + arr[j] == sumNumber) {
                    printf("Cap so co tong bang %d la: %d va %d",sumNumber,arr[i], arr[j]);
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            printf("Khong tim thay cap so co tong thoa man",sumNumber);
        }
    }else {
        printf("So luong phan tu phai lon hon 0");
    }

    return 0;
}
