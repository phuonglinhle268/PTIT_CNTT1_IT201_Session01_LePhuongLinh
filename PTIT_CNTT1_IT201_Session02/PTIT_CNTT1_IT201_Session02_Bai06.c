#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, pos, value;

    printf("Nhap so luong phan tu co trong mang (0<n<=100): ");
    scanf("%d", &n);

    if (n>0 && n<=100) {
        int *arr = (int*)malloc((n+1)*sizeof(int));
        for (i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        printf("Nhap vi tri muon them phan tu: ");
        scanf("%d", &pos);
        if (pos>=0 && pos<=n) {
            printf("Nhap gia tri cua phan tu muon them: ");
            scanf("%d", &value);
            for (i = 0; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = value;
            n++;

            printf("Mang sau khi them phan tu la: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
        }else {
            printf("Vi tri them vao khong hop le");
        }
    } else {
        printf("So luong khong hop le");
    }
    return 0;
}
