#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file inputs a telephone number, tokenizes it, concatenates the number
 * into a string, converts it to ints, and displays it.
 ****** */

int main() {
    char number[100];
    char area[10], fthree[10], lfour[10], phone[20];

    printf("Enter telephone number in the form (555) 555-5555:\n ");
    fgets(number, sizeof(number), stdin);
    number[strcspn(number,"\n")] = '\0';
   
    char* token = strtok(number, " ()");
    strcpy(area, token);

    token = strtok(NULL, " -");
    strcpy(fthree, token);

    token = strtok(NULL, " -");
    strcpy(lfour, token); 

    strcpy(phone, fthree);
    strcat(phone, lfour);

    int areaCode = atoi(area);
    int pnumber = atoi(phone);

    printf("Area Code:\n");
    printf("%d\n", areaCode);
    printf("Phone Number: \n");
    printf("%d\n", pnumber);

    return 0;
}

