#include <stdio.h>

int main() {

    printf("For Loop: \n\n");
    for (int i=0; i<10; i++){
        printf("%d\n", i);
    }


    printf("\n\nWhile Loop: \n");
    int k;

    do {
        printf("%d\n", k);
        k += 1;

    }while (k <= 10);

    return 0;
}
