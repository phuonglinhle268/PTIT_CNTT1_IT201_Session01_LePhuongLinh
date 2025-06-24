#include <stdio.h>
#define MAX 1000

int mainCross(int arr[MAX][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][i];
    }
    return sum;
}

int extraCross(int arr[MAX][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][n - i - 1];
    }
    return sum;
}

int main() {
    int arr[MAX][MAX];
    int rows, cols;
    printf("Nhap so hang (0<rows<1000): ");
    scanf("%d", &rows);
    printf("Nhap so cot (0<cols<1000): ");
    scanf("%d", &cols);

    if (rows <= 0|| cols <= 0) {
        printf("So cot/hang phai lon hon 0");
    } else if (rows >1000 || cols >1000) {
        printf("So cot/hang khong duoc qua 1000");
    } else if (rows != cols) {
        printf("Day phai la ma tran vuong");
    }else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("Nhap cot %d, hang %d ",i+1, j+1);
                scanf("%d", &arr[i][j]);
            }
        }
        int sum1 =  mainCross(arr, rows);
        int sum2 =  extraCross(arr, rows);
        printf("Tong duong cheo chinh la: %d\n",sum1);
        printf("Tong duong cheo phu la: %d\n",sum2);
    }
    return 0;
}
