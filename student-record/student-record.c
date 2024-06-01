#include <stdio.h>


#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50


void banner(); // Fonksiyon prototipi

int main() {
    int studentChoice, studentNote;
    char studentName[MAX_STUDENTS][MAX_NAME_LENGTH];
    int studentRecord[MAX_STUDENTS];

    banner(); // banner fonksiyonunu çağır

    while(1){    
        printf("1. Enter Student Record\n");
        printf("2. Enter Student Note\n");
        printf("3. Delete Student Record\n");
        printf("4. Show Records\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &studentChoice);

        switch (studentChoice) {
            case 1:
                printf("Enter a student name: ");
                scanf("%s", studentName[studentChoice - 1]); // Geçerli bir indeks kullanın

                printf("Enter a student note: ");
                scanf("%d", &studentNote);

                studentRecord[studentChoice - 1] = studentNote; // Geçerli bir indeks kullanın
                                                            //
                break;

            case 2:
                break;

            case 3: 
                break;

            case 4:
                printf("Enter the student number to print: ");
                scanf("%d", &studentChoice);

                if (studentChoice >= 1 && studentChoice <= MAX_STUDENTS) {
                    printf("Student Name: %s\n", studentName[studentChoice - 1]);
                    printf("Student Note: %d\n\n", studentRecord[studentChoice - 1]);
                } else {
                    printf("Invalid student number!\n");
                }
                break;

            case 5:
                printf("Exiting program...");
                return 0;


            default:
                printf("Please select a valid option!");
        }
    }

    return 0;
}

// banner fonksiyonunun tanımı
void banner() {
printf("     ,-.  .         .         .     ,-.                    .\n");
printf("    (   ` |         |         |     |  )                   |    \n");
printf("     `-.  |-  . . ,-| ,-. ;-. |-    |-<  ,-. ,-. ,-. ;-. ,-|    \n");
printf("    .   ) |   | | | | |-' | | |     |  \\ |-' |   | | |   | |   \n");
printf("     `-'  `-' `-` `-' `-' ' ' `-'   '  ' `-' `-' `-' '   `-'    \n");
printf("=================================================================\n");
                                                         
}

