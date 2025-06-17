#include <stdio.h>
void printDouble(int n){
int i = 1;
while (i < n) {
printf("%d\n", i);
i *= 2;
}
}

//Độ phức tạp thời gian: O(log n)