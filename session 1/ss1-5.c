#include <stdio.h>
void sortNumber(int arr[], int n){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
void arrayNumber(int arr[], int n){
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}
int main(){
  int arr[] = {1,3,2,7,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Mang ban dau: ");
  arrayNumber(arr, n);
  sortNumber(arr, n);
  printf("Mang sau khi sap xep: ");
  arrayNumber(arr, n);

  return 0;
}

//Độ phức tạp thời gian: O(n^2)
//Sử dụng bubble sort để sắp xếp mảng số nguyên, 2 vòng lặp for lồng nhau

//Độ phức tạp ko gian: O(1)
//các biến dùng ko ph thuộc vào kích thước mảng