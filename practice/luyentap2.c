#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int maMon[20];
    char tenMon[100];
    int tinChi;
} MonHoc;

typedef struct nowNode {
    MonHoc data;
    struct nowNode* next;
} nowNode;

typedef struct finishNode {
    MonHoc data;
    struct finishNode* next;
    struct finishNode* prev;
} finishNode;

//Node hang doi (sinh vien cho)
typedef struct QNode {
    char tenSinhVien[100];
    struct QNode* next;
} QNode;

nowNode* head = NULL;
nowNode* lastAdded = NULL;
finishNode* finishHead = NULL;
finishNode* finishTail = NULL;
QNode* queueFront = NULL;
QNode* queueRear = NULL;

void add() {
    nowNode* newNode = (nowNode*)malloc(sizeof(nowNode));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho");
        return;
    }
    printf("Nhap ma mon hoc: ");
    scanf("%d", &newNode -> data.id);
    getchar();
    printf("Nhap ten mon: ");
    fgets(newNode -> data.tenMon, sizeof(newNode->data.tenMon), stdin);
    newNode -> data.tenMon[strcspn(newNode -> data.tenMon, "\n")] = '\0';
    printf("Nhap so tin chi: ");
    scanf("%d", &newNode -> data.tinChi);
    newNode -> next = head;
    head = newNode;
    lastAdded = newNode;
    printf("Them mon hoc thanh cong\n");
}
//danh sach khoa hoc dang dien ra
void displayCourse() {
    nowNode* temp = head;
    if (!temp) {
        printf("Danh sach trong");
        return;
    }
    printf("Danh sach khoa hoc: \n");
    while (temp) {
        printf("ID: %d | Ten: %s | Tin chi: %d\n", temp->data.maMon, temp->data.tenMon, temp->data.tinChi);
        temp = temp -> next;
    }
}

//sap xep theo ten
void sort() {
    if (head == NULL) {
        return;
    }
    nowNode* i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->data.tenMon, j->data.tenMon) > 0) {
                MonHoc temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Danh sach sau sap xep: \n");
    displayCourse();
}

//tim theo ma mon
void search() {
    char ma[20];
    printf("Nhap ma mon can tim: ");
    scanf("%s", ma);
    nowNode* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp -> data.maMon, ma) == 0) {
            printf("ID: %d | Ten: %s | Tin chi: %d\n", temp->data.maMon, temp->data.tenMon, temp->data.tinChi);
            found = 1;
        }
        temp = temp -> next;
    }
    if (!found) {
        printf("Khong tim thay ma mon hoc tuong ung\n");
    }
}

void tongTinChi() {
    int tong = 0;
    nowNode* temp = head;
    while (temp != NULL) {
        tong += temp->data.tinChi;
        temp = temp -> next;
    }
    printf("Tong tin chi da dang ki: %d\n", tong);
}

//chuyen mon sang danh sach hoan thanh
void chuyenSangHoanThanh() {
    char ma[20];
    printf("Nhap ma mon can chuyen: ");
    scanf("%s", ma);
    nowNode* temp = head;
    nowNode* prev = NULL;
    while (temp != NULL && strcmp(temp -> data.maMon, ma) != 0) {
        prev = temp;
        temp = temp -> next;
    }
    if (temp == NULL) {
        printf("Khong tim thay ma mon\n");
        return;
    }
    if (prev == NULL) {
        head = temp -> next;
    } else {
        prev -> next = temp -> next;
    }
    finishNode* newNode = (finishNode*)malloc(sizeof(finishNode));
    newNode -> data = temp -> data;
    newNode -> prev = finishTail;
    newNode -> next = NULL;
    if (finishTail != NULL) {
        finishTail -> next = newNode;
    } else {
        finishTail = newNode;
    }
    finishTail = newNode;
    free(temp);
    printf("Da chuyen thanh cong");
}

int main() {
    int choice;
    do {
        printf("\n-----MENU-----\n");
        printf("1. Them mon hoc\n");
        printf("2. Tim kiem mon hoc theo ma mon\n");
        printf("3. Sap xep danh sach theo ten\n");
        printf("4. Tinh tong so tin chi\n");
        printf("5. Chuyen mot mon hoc sang danh sach hoan thanh\n");
        printf("6. Hoan tac thao tac them mon gan nhat\n");
        printf("7. Quan li danh sach sinh vien cho\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                displayCourse();
                break;
            case 2:
                search();
                break;
            case 3:
                sort();
                break;
            case 4:
                tongTinChi();
                break;
            case 5:
                chuyenSangHoanThanh();
                break;
            case 6:

                break;
            case 7:

                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le");
                break;
        }
    } while (choice != 8);
    return 0;
}