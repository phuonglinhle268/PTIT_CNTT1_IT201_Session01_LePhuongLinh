#include <stdio.h>

//tìm kiếm nhị phân đệ quy
int binarySearchRecursion(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        binarySearchRecursion(arr, mid + 1, high, key);
    }else {
        binarySearchRecursion(arr, low, mid - 1, key);
    }
}

int main(void) {

}
