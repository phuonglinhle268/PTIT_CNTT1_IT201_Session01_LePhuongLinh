#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    if (n>0) {
        int arr[n];
        for (int i =0; i <n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        int doixung = 0;
        for (int i=0; i<n/2; i++) {
            if (arr[i]== arr[n-1-i]) {
                printf("Cap doi xung: (%d, %d)\n",arr[i], arr[n-1-i]);
                doixung = 1;
            }
        }
        if (!doixung) {
            printf("Khong co phan tu doi xung");
        }
    }else {
        printf("So luong phan tu phai lon hon 0");
    }
    return 0;
}
