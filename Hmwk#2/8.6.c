#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file inputs a line of text into char array s[100] and displays the line
 * in uppercase letters and in lowercase letters.
 ****** */

int main() {
    char s[100];
    printf("Enter a line of text:\n");
    scanf("%s", s);

    printf("Uppercase: ");
    for (int i = 0; s[i] != '\0'; i++) {
        putchar(toupper(s[i]));
    }

    printf("\nLowercase: ");
    for (int i = 0; s[i] != '\0'; i++) {
        putchar(tolower(s[i]));
    }
}

