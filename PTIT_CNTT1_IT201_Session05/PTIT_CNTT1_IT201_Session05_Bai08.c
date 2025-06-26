#include <stdio.h>
#include <string.h>
#include <ctype.h>

int changeStr(char str[], int i) {
    if (str[i] == '\0') {
        return 0;
    }
    return (str[i] - '0') + 10 * changeStr(str, i + 1);
}

int number(char str[]) {
    for (int i=0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (strlen(str) == 0) {
        printf("Chuoi trong");
        return 1;
    }

    if (!number(str)) {
        printf("Chuoi khong hop le");
        return 1;
    }

    int result = changeStr(str, 0);
    printf("%d\n", result);

    return 0;
}