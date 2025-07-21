#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    int credit;
} Course;

typedef struct nowNode {
    Course data;
    struct nowNode* next;
} nowNode;

typedef struct finishNode {
    Course data;
    struct finishNode* next;
    struct finishNode* prev;
} finishNode;

nowNode* head = NULL;
finishNode* finishHead = NULL;
finishNode* finishTail = NULL;

void add() {
    nowNode* newNode = (nowNode*)malloc(sizeof(nowNode));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho");
        return;
    }
    printf("Nhap id khoa hoc: ");
    scanf("%d", &newNode -> data.id);
    getchar();
    printf("Nhap ten khoa hoc: ");
    fgets(newNode -> data.title, 100, stdin);
    newNode -> data.title[strcspn(newNode -> data.title, "\n")] = '\0';
    printf("Nhap so tin chi: ");
    scanf("%d", &newNode -> data.credit);
    newNode -> next = head;
    head = newNode;
}
//danh sach khoa hoc dang dien ra
void displayCourse() {
    nowNode* temp = head;
    if (!temp) {
        printf("Danh sach trong\n");
        return;
    }
    printf("Danh sach khoa hoc: \n");
    while (temp) {
        printf("ID: %d | Ten: %s | Tin chi: %d\n", temp->data.id, temp->data.title, temp->data.credit);
        temp = temp -> next;
    }
}
//danh sach khoa hoc da dien ra
// void displayCompleted () {
//     finishNode* temp = finishHead;
//     if (!temp) {
//         printf("Danh sach trong");
//         return;
//     }
//     printf("Danh sach khoa hoc da hoan thanh: \n");
//     while (temp) {
//         printf("ID: %d | Ten: %s | Tin chi: %d\n", temp->data.id, temp->data.title, temp->data.credit);
//         temp = temp -> next;
//     }
// }

//xoa theo id
void delete(){
    int id;
    printf("Nhap id cho khoa hoc muon xoa: ");
    scanf("%d", &id);
    nowNode* temp = head;
    nowNode* prev = NULL;
    //int found=0;
    //while(temp!=NULL)
    while (temp && temp -> data.id != id) {
        prev = temp;
        temp = temp -> next;
        // if (strcmp(temp->data.title, name) == 0) {
        //     found = 1;
        //     if (prev == NULL) {
        //         head = temp->next;
        //     } else {
        //         prev->next = temp->next;
        //     }
        //     free(temp);
        //     printf("Da xoa khoa hoc voi ten: %s\n", name);
        //     return;
        // }
    }
    if (!temp){ //!found
        printf("Khong thay khoa hoc");
        return;
    } else {
        if (prev == NULL) {
            head = temp -> next;
        } else {
            prev -> next = temp -> next;
        }
        free(temp);
        printf("Da xoa khoa hoc voi ID: %d\n", id);
    }
}
//char name[100];
// getchar();
// printf("Nhap ten khoa hoc can tim: ");
// fgets(name, sizeof(name), stdin);
// name[strcspn(name, "\n")] = '\0';

//update theo id
void update() {
    int id;
    printf("Nhap ID khoa hoc muon cap nhat: ");
    scanf("%d", &id);
    getchar();
    nowNode *temp = head;
    while (temp != NULL && temp -> data.id != id) {
        temp = temp -> next;
    }
    if (!temp) {
        printf("Khong thay khoa hoc\n");
        return;
    }
    printf("Nhap ten moi cap nhat: ");
    fgets(temp -> data.title, 100, stdin);
    temp -> data.title[strcspn(temp -> data.title, "\n")] = '\0';
    printf("Nhap so tin moi: ");
    scanf("%d", &temp->data.credit);
    printf("Cap nhat thanh cong\n");
}

//danh dau da hoan thanh
void mark() {
    int id;
    printf("Nhap ID can danh dau hoan thanh: ");
    scanf("%d", &id);
    nowNode* temp = head;
    nowNode* prev = NULL;
    while (temp != NULL && temp->data.id != id) {
        prev = temp;
        temp = temp -> next;
    }
    if (!temp) {
        printf("Khong thay khoa hoc");
        return;
    } else {
        if (prev == NULL) {
            head = temp -> next;
        } else {
            prev -> next = temp -> next;
        }
        finishNode* newNode = (finishNode*)malloc(sizeof(finishNode));
        if (newNode == NULL) {
            printf("Khong the cap phat bo nho");
            return;
        }
        newNode -> data = temp -> data;
        newNode -> next = NULL;
        if (finishTail != NULL) {
            finishTail -> next = newNode;
            newNode -> prev = finishTail;
        } else {
            finishHead = newNode;
            newNode -> prev = NULL;
        }
        finishTail = newNode;
        free(temp);
        printf("Da danh dau hoan thanh\n");
    }
}
//sap xep theo credit
void sort() {
    nowNode* i;
    int swapped;
    for (i = head; i != NULL; i = i->next) {
        swapped = 0;
        nowNode* prev = NULL;
        nowNode* j = head;
        while (j->next != NULL) {
            nowNode* next = j->next;
            //if(strcmp(j->data.title, next->data.title) > 0)
            if (j->data.credit > next->data.credit) {
                if (prev == NULL) {
                    head = next;
                } else {
                    prev -> next = next;
                }
                j -> next = next -> next;
                next -> next = j;
                swapped = 1;
                prev = next;
            } else {
                prev = j;
                j = j -> next;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    printf("Danh sach sau khi sap xep: ");
    nowNode* temp = head;
    while (temp) {
        printf("ID: %d | Ten: %s | Tin chi: %d\n", temp->data.id, temp->data.title, temp->data.credit);
        temp = temp -> next;
    }
}
//tim theo ten
void search() {
    char name[100];
    getchar();
    printf("Nhap ten khoa hoc can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    nowNode* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strstr(temp -> data.title, name) != NULL) {
            printf("ID: %d | Ten: %s | Tin chi: %d\n", temp->data.id, temp->data.title, temp->data.credit);
            found = 1;
        }
        temp = temp -> next;
    }
    if (!found) {
        printf("Khong tim thay khoa hoc tuong ung\n");
    }
}
//int id, gán
//nowNode* temp = head;
//while ...
// if (temp->data.id == id){

int main() {
    int choice;
    do {
        printf("\n-----MENU-----\n");
        printf("1. Them khoa hoc\n");
        printf("2. Hien thi danh sach khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Cap nhat thong tin khoa hoc\n");
        printf("5. Danh dau khoa hoc da hoan thanh\n");
        printf("6. Sap xep khoa hoc theo tin chi\n");
        printf("7. Tim kiem khoa hoc theo ten\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                displayCourse();
                break;
            case 3:
                delete();
                break;
            case 4:
                update();
                break;
            case 5:
                mark();
                break;
            case 6:
                sort();
                break;
            case 7:
                search();
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