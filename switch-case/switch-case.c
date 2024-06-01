#include <stdio.h>

int main() {

    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int inputDay;

    printf("Enter a number between \(1-7): ");
    scanf("%d", &inputDay);
    
    switch (inputDay) {
    
        case 1:
            printf("%s", days[0]);
            break;

        case 2:
            printf("%s", days[1]);
            break;

        case 3:
            printf("%s", days[2]);
            break;

        case 4:
            printf("%s", days[3]);
            break;

        case 5:
            printf("%s", days[4]);
            break;

        case 6:
            printf("%s", days[5]);
            break;

        case 7:
            printf("%s", days[6]);
            break;

        default:
            printf("The number you have entered is not between 1-7");
    }

    return 0;
}
