#include <stdio.h>
#define MAX 1000

int maxNumber(int arr[MAX][MAX], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int minNumber(int arr[MAX][MAX], int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int  main() {
    int arr[MAX][MAX];
    int cols, rows;
    printf("Nhap so hang (0<rows<1000): ");
    scanf("%d", &rows);
    printf("Nhap so cot (0<cols<1000): ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("So cot/hang phai lon hon 0");
    } else if (rows > 1000 || cols > 1000) {
        printf("So cot/hang khong duoc qua 1000");
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("Nhap  cot %d, hang %d: ", i+1, j+1);
                scanf("%d", &arr[i][j]);
            }
        }
        int max = maxNumber(arr, rows, cols);
        int min = minNumber(arr, rows, cols);
        printf("So lon nhat la: %d\n", max);
        printf("So nho nhat la: %d\n", min);

    }
    return 0;
}
