#include <stdio.h>
#define MAX 100

int sumK(int arr[MAX][MAX], int cols, int k) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += arr[k][j];
    }
    return sum;
}

int main() {
    int arr[MAX][MAX];
    int cols, rows;
    printf("Nhap so hang (0<rows<1000)");
    scanf("%d", &rows);
    printf("Nhap so cot (0<cols<1000)");
    scanf("%d", &cols);
    if (cols < 0 || rows < 0) {
        printf("So hang/cot phai lon hon 0");
    } else if (rows > 1000 || cols > 1000) {
        printf("So hang/cot khong duoc qua 1000");
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("Nhap hang %d, cot %d: ", i+1, j+1);
                scanf("%d", &arr[i][j]);
            }
        }
        int k;
        printf("Nhap chi so hang k (0<=k<%d: ", rows);
        scanf("%d", &k);
        if (k < 0 || k > rows) {
            printf("Khong hop le");
        }
        int sum = sumK(arr, cols, k);
        printf("Tong cac phan tu cua hang %d la: ", k, sum);
    }
    return 0;
}
