#include <stdio.h>



int factorial(int num){
    int fact=0;

    if (num == 0){
        return 1;

    } else{
        return num * factorial(num - 1);
    }
}


int main() {

    int num;
    printf("Calculate factorial: ");
    scanf("%d", &num);  

    printf("Factorial: %d", factorial(num));

    return 0;
}
