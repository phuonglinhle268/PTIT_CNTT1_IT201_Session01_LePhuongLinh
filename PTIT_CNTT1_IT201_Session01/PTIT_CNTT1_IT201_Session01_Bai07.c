#include <stdio.h>
bool dupNumber(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap phan tu tu 0-1000: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (dupNumber(arr, n)) {
        printf("Co phan tu trung lap\n");
    } else {
        printf("Khong co phan tu trung lap\n");
    }
    return 0;
}
//Check way 1:
// int main(void) {
//     return 0;
// }
// int checkDup(int numbers[], int size) {
//     //xet tung ptu trong mang
//     for (int i = 0; i < size; i++) {
//         //dem tung ptu dang dc xet di ss voi tat ca cac ptu con lai
//         for (int j = i+1; j < size; j++) {
//             if (numbers[i] == numbers[j]) {
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

//Độ phức tạp thời gian: O(n^2)
//Độ phức tạp không gian: O(1)

// //Cách 2:
void checkNumber(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
bool numberDuplicate(int arr[], int n) {
    checkNumber(arr, n);
    for (int i = 0; i < n-1; i++) {
        if (arr[i] == arr[i+1]) {
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap phan tu tu 0-1000: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (numberDuplicate(arr, n)) {
        printf("Co phan tu trung lap\n");
    } else {
        printf("Khong co phan tu trung lap\n");
    }
    return 0;
}
// //check way 2
// int checkDup(int numbers[], int size);
// int checkDupSubArray(int numbers[], int size) {
//     int seenNumbers[1001];
//     //tao ra mang phu chua so luong ptu bang voi gioi han do lon cua mang dc xet
//     //duyet qua tung ptu trong mang ban dau
//     for (int i = 0; i < size; i++) {
//         //neu ptu dc xet da co ptu t.ung trong mang phu la 1, thi tra ve gtri 1
//         if (seenNumbers[numbers[i]] == 1) {
//             return 1;
//         }
//         //ung voi ptu dc xet, tang gtri cua ptu t/ung trong mang phu len  1
//         seenNumbers[numbers[i]] = 1;
//     }
// };
//Độ phức tạp thời gian: O(n^2)
//Độ phức tạp không gian: O(1)