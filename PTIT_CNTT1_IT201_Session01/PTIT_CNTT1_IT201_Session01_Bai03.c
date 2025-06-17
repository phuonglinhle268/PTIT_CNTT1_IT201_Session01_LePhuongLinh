#include <stdio.h>
int* mallocArray(int n){
  int* arr = (int*)malloc(n*sizeof(int));
  for(int i=0; i<n; i++){
     arr[i] = i;
  }
  return arr;
}
//Do phức tạp thời gian O(n)
