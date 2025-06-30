#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Nhap chuoi bat ki: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Before: %s\n", str);

    int string = strlen(str);
    for (int i =0; i< string-1; i++) {
        for (int j=i+1; j < string; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    printf("After: %s\n", str);

    return 0;
}