#include <stdio.h>

int sumNumber(int a, int b) {
    if (a > b) {
        return 0;
    }
    return a + sumNumber(a+1, b);
}
int main() {
    int a, b;
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);
    if (a > 0 || b > 0) {
        int result = sumNumber(a, b);
        printf("Tong 2 so: %d", result);
    }else {
        printf("Gia tri khong hop le");
    }
    return 0;
}
