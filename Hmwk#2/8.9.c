#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file inputs four strings representing integers, converts the strings to
 * integers, sums the values, and prints the total of the four values.
 ****** */

int main() {
    char string1[10];
    char string2[10];
    printf("Enter a string: \n");
    scanf("%s" ,string1);
    printf("Enter a string: \n");
    scanf("%s" ,string2);
    int res = strcmp(string1, string2);
    if(res == 0)
        printf("string1 equals string2\n");
    else if(res > 0)
	printf("string1 is greater than string2\n");
    else
	printf("string1 is less than string2\n");

}
