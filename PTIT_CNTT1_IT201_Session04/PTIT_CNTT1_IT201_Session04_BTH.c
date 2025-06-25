#include <stdio.h>

int main(void) {
    int numbers[10]={1,2,3,4,5,6,7,8,9,10};
    return 0;
}
int linearSearch(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[], int size, int value) {
    int low = 0, high = size-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == value) {
            return mid;
        }else if (array[mid] < value) {
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return -1;
}