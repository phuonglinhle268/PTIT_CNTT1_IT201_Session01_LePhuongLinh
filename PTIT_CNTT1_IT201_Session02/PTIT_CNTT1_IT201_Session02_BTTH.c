#include <stdio.h>
#include <stdlib.h>

int *insertToArray(int *numbers, int *size, int value);
void printArray(int *numbers, int size);
int *deleteFromArray(int *numbers, int *size, int value, int deletePos) {
    //ktra vi tri muon xoa
    if (deletePos<0 || deletePos > (*size-1)) {
        printf("Vi tri khong hop le\n");
        return numbers;
    }
    //dich cac ptu phia sau ptu muon xoa len phia trc
    for (int i=deletePos; i<(*size-1); i++) {}
    //cap nhat lai bo nho
}
int main(void) {
    int choice;
    int *numbers = NULL;
    int size = 0;
    do {
        printf("\tMENU\n");
        printf("1. Them phan tu\n ");
        printf("2. Hien thi \n");
        printf("3. Xoa phan tu\n ");
        printf("4. Thoat\n");
        printf("Nhap lua chon: \n ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                numbers = insertToArray(numbers, &size, 1);
                numbers = insertToArray(numbers, &size, 2);
                numbers = insertToArray(numbers, &size, 3);
                numbers = insertToArray(numbers, &size, 4);
                break;
            case 2:
                printArray(numbers, size);
                break;
            case 3:
                numbers =
                break;
            case 4:
                printf("Thoat\n");
                break;
        }
    }while (choice != 4);
}
int *insertToArray(int *numbers, int *size, int value) {
    //cap phat lai bo nho cho mang
    numbers=(int*)realloc(numbers, (size+1)*sizeof);
    //gan lai gia tri cho ptu cuoi cung
    numbers[*size]=value;
    (*size)++;
    return numbers;
}
void printArray(int *numbers, int size) {

}
