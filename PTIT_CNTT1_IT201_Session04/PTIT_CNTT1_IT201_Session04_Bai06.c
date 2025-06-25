#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};

int main() {
    struct Student students[5];
    int studentID =0;
    int found = 0;

    for (int i = 0; i <5; i++) {
        printf("Nhap thong tin cua sinh vien %d: \n", i+1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        getchar();
        printf("Ten: ");
        fgets(students[i].name, sizeof(students[i].name),stdin);
        students[i].name[strcspn(students[i].name, "\n")]='0';
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
    }
    printf("Nhap ID cua sinh vien can tim: ");
    scanf("%d", &studentID);

    for (int i =0; i <5; i++) {
        if (students[i].id == studentID) {
            printf("ID: %d\n", students[i].id);
            printf("Ten: %s\n", students[i].name);
            printf("Tuoi: %d\n", students[i].age);
            found = 1;
            return 0;
        }
    }
    if (!found) {
        printf("Sinh vien khong ton tai");
    }
    return 0;
}