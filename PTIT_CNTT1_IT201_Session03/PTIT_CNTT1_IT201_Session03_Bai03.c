#include <stdio.h>
#include <stdlib.h>

float checkNumber(int *arr, int n) {
    int sum=0;
    int count=0;
    for (int i=0; i<n; i++) {
        if (arr[i] % 2 ==0) {
            sum += arr[i];
            count++;
        }
    }
    if (count==n) return 0;
    return (float)sum/count;
}
int main() {
    int n,i;
    printf("Nhap so luong phan tu co trong mang (0<n<1000): ");
    scanf("%d", &n);
    if (n>0 && n<1000) {
        int* arr = (int*)malloc(n*sizeof(int));
        if (arr == NULL) {
            printf("Khong cap phat duoc bo nho");
            return 1;
        }
        for (int i=0; i<n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        float result = checkNumber(arr, n);
        if (result==0) {
            printf("Mang khong co so chan");
        } else {
            printf("Trung binh cong cac so chan co trong mang la: %.f", result);
        }
        free(arr);
    } else {
        printf("So luong phan tu khong hop le");
    }
    return 0;
}
