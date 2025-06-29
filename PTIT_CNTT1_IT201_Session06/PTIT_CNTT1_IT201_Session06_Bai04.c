#include <stdio.h>

void thapHN(int n, char from, char to, char end) {
    if (n==1) {
        printf("Dia 1 di chuyen tu %c sang %c\n", from, end);
        return;
    }
    thapHN(n-1, from, end, to);

    printf("Dia %d di chuyen tu %c sang %c\n", n, from, end);
    thapHN(n-1, to, from, end);
}

int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);

    if (n>0) {
        printf("Cac buoc chuyen dia tu cot A sang cot C: \n");
        thapHN(n, 'A', 'B', 'C');
    } else {
        printf("So luong dia khong hop le");
    }
    return 0;
}