#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file reads a series of strings and prints only those that end with the
 * letters "ed".
 ****** */

int main() {
    char str[100];
    int num, length;

    printf("How many strings do you want to enter? ");
    scanf("%d", &num);

    getchar();

    // Loop to input strings and check if they end with "ed"
    for (int i = 0; i < num; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(str, sizeof(str), stdin);

        // Remove newline character if present
        str[strcspn(str, "\n")] = '\0';

        length = strlen(str);

        if (length >= 2 && str[length - 2] == 'e' && str[length - 1] == 'd') {
            printf("%s ends with 'ed'\n", str);
        }
    }

    return 0;
}


