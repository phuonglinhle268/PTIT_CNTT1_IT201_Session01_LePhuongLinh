#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[50];
    int priority;
    char deadline[100];
} Task;

 typedef struct nowNode {
     Task data;
     struct nowNode* next;
 } nowNode;

typedef struct finishNode {
    Task data;
    struct finishNode* next;
    struct finishNode* prev;
} finishNode;

nowNode* head = NULL;
finishNode* finishHead = NULL;
finishNode* finishTail = NULL;

void add() {
    nowNode* newNode = (nowNode*)malloc(sizeof(nowNode));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        return;
    }
    printf("Nhap id cho nhiem vu: ");
    scanf("%d", &newNode->data.id);
    getchar();
    printf("Nhap tieu de: ");
    fgets(newNode -> data.title, 50, stdin);
    newNode -> data.title[strcspn(newNode -> data.title, "\n")] = '\0';
    printf("Nhap muc do uu tien nhiem vu: ");
    scanf("%d", &newNode -> data.priority);
    getchar();
    printf("Nhap thoi gian hoan thanh: ");
    fgets(newNode -> data.deadline, 100, stdin);
    newNode -> data.deadline[strcspn(newNode -> data.deadline, "\n")] = '\0';
    newNode -> next = head;
    head = newNode;
    printf("Da them vao danh sach\n");
}

void display() {
    nowNode* temp = head;
    if (!temp) {
        printf("Danh sach rong\n");
        return;
    }
    while (temp) {
        printf("ID: %d | Title: %s | Priority: %d | Deadline: %s\n",
            temp -> data.id, temp -> data.title, temp -> data.priority, temp -> data.deadline);
        temp = temp -> next;
    }
}
void delete() {
    int id;
    printf("Nhap id nhiem vu muon xoa: ");
    scanf("%d", &id);
    nowNode* temp = head;
    nowNode* prev = NULL;
    while (temp && temp -> data.id != id) {
        prev = temp;
        temp = temp -> next;
    }
    if (!temp){
        printf("Khong thay nhiem vu");
        return;
    } else {
        if (prev == NULL) {
            head = temp -> next;
        } else {
            prev -> next = temp -> next;
        }
        free(temp);
        printf("Da xoa nhiem vu voi ID: %d\n", id);
    }
}
void update() {
    int id;
    printf("Nhap ID nhiem vu muon cap nhat: ");
    scanf("%d", &id);
    getchar();
    nowNode *temp = head;
    while (temp != NULL && temp -> data.id != id) {
        temp = temp -> next;
    }
    if (!temp) {
        printf("Khong thay nhiem vu\n");
        return;
    }
    printf("Nhap tieu de moi cap nhat: ");
    fgets(temp -> data.title, 50, stdin);
    temp -> data.title[strcspn(temp -> data.title, "\n")] = '\0';
    printf("Nhap muc do uu tien: ");
    scanf("%d", &temp->data.priority);
    getchar();
    printf("Nhap thoi gian hoan thanh: ");
    fgets(temp -> data.deadline, 100, stdin);
    temp -> data.deadline[strcspn(temp -> data.deadline, "\n")] = '\0';
    printf("Cap nhat thanh cong\n");
}
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
        printf("Khong thay nhiem vu\n");
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
void sort() {
    nowNode* i;
    int swapped;
    if (!head) {
        return;
    }
    do {
        swapped = 0;
        nowNode* temp = head;
        while (temp -> next != NULL) {
            if (temp -> data.priority > temp -> next -> data.priority) {
                Task tmp = temp -> data;
                temp -> data = temp -> next -> data;
                temp -> next -> data = tmp;
                swapped = 1;
            }
            temp = temp -> next;
        }
    } while (swapped);
    printf("Danh sach sau sap xep\n");
    display();
}

void search() {
    char name[100];
    getchar();
    printf("Nhap tieu de can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    nowNode* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strstr(temp -> data.title, name) != NULL) {
            printf("ID: %d | Title: %s | Priority: %d | Deadline: &s\n", temp->data.id, temp->data.title, temp->data.priority, temp->data.deadline);
            found = 1;
        }
        temp = temp -> next;
    }
    if (!found) {
        printf("Khong tim nhiem vu tuong ung\n");
    }
}
int main() {
    int choice;
    do {
        printf("\n-----MENU-----\n");
        printf("1. Them moi nhiem vu\n");
        printf("2. Hien thi nhiem vu\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhat nhiem vu\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu\n");
        printf("7. Tim kiem  nhiem vu\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
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
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 8);
    return 0;
}

