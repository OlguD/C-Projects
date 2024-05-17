#include <stdio.h>


int main() {

    int number;
    
    while(1) {
        printf("Write a number to determine pozitive or negative: ");
        scanf("%d", &number);

        if (number < 0) {
            printf("%d is negative\n", number);

        } else if (number > 0) {
            printf("%d is positive\n", number);

        } else{
            printf("%d is zero\n", number);
        }
    }
    
    return 0;
}
