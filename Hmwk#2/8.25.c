#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file inputs an ASCII code and prints the corresponding character.
 ****** */

int main() {
    int acode;

    printf("Enter an ASCII code: ");
    scanf("%d", &acode);

    if (acode >= 0 && acode <= 127) {
        printf("The corresponding character to ascii code %d is: %c\n", acode,
		       	acode);
    }

    return 0;
}


