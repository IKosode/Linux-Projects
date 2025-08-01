#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file inputs four strings representing integers, converts the strings to
 * integers, sums the values, and prints the total of the four values.
 ****** */

int main() {
    int num1, num2, num3, num4, sum;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    sum = num1 + num2 + num3 + num4;

    printf("The sum of the four values is: %d\n", sum);

    return 0;
}
