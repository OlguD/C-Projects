#include <stdio.h>

int main() {
    int numberStudents, note;
    float average = 0, totalNotes = 0;

    printf("Enter a class quota: ");
    scanf("%d", &numberStudents);
    int classNotes[numberStudents];

    for (int i = 0; i < numberStudents; i++) {
        printf("Enter %d. student's note: ", i + 1);
        scanf("%d", &note);
        classNotes[i] = note;
        totalNotes += note;
    }

    average = totalNotes / numberStudents;
    printf("Class average: %.2f\n", average);

    for (int k=0; k<numberStudents; k++){
        printf("%d - %d\n", k+1, classNotes[k]);

    }

    return 0;
}

