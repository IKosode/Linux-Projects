#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file reads a series of strings and prints only those that begin with
 * the letters "b".
 ****** */

int main() {
    char str[100];
    int num;

    printf("How many strings do you want to enter? ");
    scanf("%d", &num);

    getchar();

    // Loop to input strings and check if they begin with "b"
    for (int i = 0; i < num; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(str, sizeof(str), stdin);

        // Remove newline character if present
        str[strcspn(str, "\n")] = '\0';

        if (str[0] == 'b') {
            printf("%s begins with 'b'\n", str);
        }
    }

    return 0;
}

