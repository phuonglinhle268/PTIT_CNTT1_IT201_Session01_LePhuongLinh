#include <stdio.h>
//Cách 1:
int sumNumber (int n){
  int sum = 0;
  for (int i = 1; i <= n; i++){
    sum += i;
  }
return sum;
}
int main() {
  int n;
  printf("Nhap so nguyen n: ");
  scanf("%d", &n);
  int result = sumNumber(n);
  printf("Tong cua cac so la: %d\n ", result);
  return 0;
}
//Độ phức tạp thoi gian: O(n)
//Độ phức tạp không gian: O(1)

//Cách 2:
//int sumNumber(int n){
//return n*(n+1)/2;
//}
// int main() {
//   int n;
//   printf("Nhap so nguyen n: ");
//   scanf("%d", &n);
//   int result = sumNumber(n);
//   printf("Tong cua cac so la: %d\n ", result);
//   return 0;
// }
//Độ phuc tạp thời gian: O(1)
//Độ phức tạp ko gian: O(1)