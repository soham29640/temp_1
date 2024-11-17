#include <stdio.h>

comparenumbers(int *num1, int *num2) {
    return *num1 == *num2;
}

int main() {
    int num1, num2;

    printf("enter the number1: ");
    scanf("%d", &num1);

    printf("enter the number2: ");
    scanf("%d", &num2);

    if (comparenumbers(&num1, &num2)) {
        printf("two numbers are same\n");
    } else {
        printf("two numbers are not same\n");
    }

    return 0;
}
