#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char content[100];
    char topic[100];
    int level;
} Question;

typedef struct nowNode {
    Question data;
    struct nowNode* next;
} nowNode;

typedef struct finishNode {
    Question data;
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
    printf("Nhap ma cho cau hoi: ");
    scanf("%d", &newNode -> data.id);
    getchar();
    printf("Nhap noi dung: ");
    fgets(newNode -> data.content, 100, stdin);
    newNode -> data.content[strcspn(newNode -> data.content, "\n")] = '\0';
    printf("Nhap chu de: ");
    fgets(newNode -> data.topic, 100, stdin);
    newNode -> data.topic[strcspn(newNode -> data.topic, "\n")] = '\0';
    printf("Nhap do kho: ");
    scanf("%d", &newNode -> data.level);
    newNode -> next = head;
    head = newNode;
    printf("Da them vao danh sach\n");
}
void displayQuestion() {
    nowNode* temp = head;
    if (!temp) {
        printf("Danh sach cau hoi rong\n");
        return;
    }
    printf("Danh sach cau hoi: \n");
    while (temp) {
        printf("ID: %d | Content: %s | Topic: %s | Level: %d\n",
            temp -> data.id, temp -> data.content, temp -> data.topic, temp -> data.level);
        temp = temp -> next;
    }
}
void displayFinish() {
    finishNode* temp = finishHead;
    if (!temp) {
        printf("Danh sach rong\n");
        return;
    }
    printf("Danh sach cau hoi da luyen xong: \n");
    while (temp) {
        printf("ID: %d | Content: %s | Topic: %s | Level: %d\n",
            temp -> data.id, temp -> data.content, temp -> data.topic, temp -> data.level);
        temp = temp -> next;
    }
}
void update() {
    int id;
    printf("Nhap ID cua cau hoi muon cap nhat: ");
    scanf("%d", &id);
    getchar();
    nowNode* temp = head;
    while (temp != NULL && temp -> data.id != id) {
        temp = temp -> next;
    }
    if (!temp) {
        printf("Khong tim thay cau hoi tuong ung\n");
        return;
    }
    printf("Nhap noi dung moi: ");
    fgets(temp -> data.content, 100, stdin);
    temp -> data.content[strcspn(temp -> data.content, "\n")] = '\0';
    printf("Nhap chu de moi: ");
    fgets(temp -> data.topic, 100, stdin);
    temp -> data.topic[strcspn(temp -> data.topic, "\n")] = '\0';
    printf("Nhap do kho moi: ");
    scanf("%d",&temp -> data.level);
    printf("Cap nhat thanh cong\n");
}
void mark() {
    int id;
    printf("Nhap ID cua cau hoi da luyen: ");
    scanf("%d", &id);
    nowNode* temp = head;
    nowNode* prev = NULL;
    while (temp != NULL && temp -> data.id != id) {
        prev = temp;
        temp = temp -> next;
    }
    if (!temp) {
        printf("Khong tim thay cau hoi tuong ung\n");
        return;
    } else {
        if (prev == NULL) {
            head = temp -> next;
        } else {
            prev -> next = temp -> next;
        }
        finishNode* newNode = (finishNode*)malloc(sizeof(finishNode));
        if (newNode == NULL) {
            printf("Khong the cap phat bo nho\n");
            return;
        }
        newNode -> data = temp -> data;
        newNode -> next = NULL;
        if (finishTail == NULL) {
            finishTail -> next = newNode;
            newNode -> prev = finishTail;
        } else {
            finishHead = newNode;
            free(temp);
            printf("Cau hoi da duoc luyen\n");
        }
    }
}
void search() {
    char question[100];
    getchar();
    printf("Nhap tu khoa cho cau hoi muon tim: ");
    fgets(question, sizeof(question), stdin);
    question[strcspn(question, "\n")] = '\0';
    nowNode* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strstr(temp -> data.content, question) != NULL) {
            printf("ID: %d | Content: %s | Topic: %s | Level: %d\n",
                temp->data.id, temp->data.content, temp->data.topic, temp->data.level);
            found = 1;
        }
        temp = temp -> next;
    }
    if (!found) {
        printf("Khong thay cau hoi tuong ung\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n-----MENU-----\n");
        printf("1. Them moi cau hoi\n");
        printf("2. Hien thi danh sach cau hoi dang luyen\n");
        printf("3. Cap nhat cau hoi\n");
        printf("4. Danh dau cau hoi da luyen\n");
        printf("5. Hien thi danh sach cau hoi da luyen\n");
        printf("6. Tim kiem cau hoi theo tu khoa\n");
        printf("7. Sap xep theo do doi noi dung\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                displayQuestion();
                break;
            case 3:
                update();
                break;
            case 4:
                mark();
                break;
            case 5:
                displayFinish();
                break;
            case 6:
                search();
                break;
            case 7:
                break;
            case 8:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le");
        }
    } while (choice != 8);
    return 0;
}