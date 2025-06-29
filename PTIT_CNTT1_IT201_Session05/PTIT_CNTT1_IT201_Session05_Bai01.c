#include <stdio.h>

void countDown(int n) {
    if (n == 0) {
        return;
    }
    countDown(n-1);
    printf("%d\n", n);
}
int main() {
    int n;
    printf("Nhap mot so nguyen duong bat ki: ");
    scanf("%d", &n);
    if (n > 0) {
        printf("Cac so tu 1 den n la:\n ", n);
        countDown(n);
    } else {
        printf("Gia tri phai lon hon 0");
    }
    return 0;
}