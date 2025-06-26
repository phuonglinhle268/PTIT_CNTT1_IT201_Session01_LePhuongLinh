#include <stdio.h>
#include <string.h>
#include <ctype.h>

int doixung(char str[], int low, int high) {
    if (low >= high) {
        return 1;
    }
    if (str[low] != str[high]) {
        return 0;
    }
    return doixung(str, low + 1, high - 1);
}

int main() {
    char str[100];
    printf("Nhap chuoi ki tu: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int result = strlen(str);
    if (doixung(str, 0, result-1)) {
        printf("Palindrome valid");
    }else {
        printf("Palindrome invalid");
    }
    return 0;
}