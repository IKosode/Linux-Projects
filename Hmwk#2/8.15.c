#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file inputs a line of text, tokenizes the line with function strtok and
 * outputs the tokens in reverse order.
 ****** */

int main() {
    char str[100];
    char* tokens[100];
    int tcount = 0;

    printf("Enter string:\n ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str,"\n")] = '\0';
    char* token = strtok(str, " ");

    while (token != NULL) {
        tokens[tcount++] = token;
        token = strtok(NULL, " ");
    }
    printf("Tokens in reverse order:\n");
    for(int i = tcount - 1; i >= 0; i--) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}

