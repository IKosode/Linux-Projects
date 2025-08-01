#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file is a variation of bubble sort that determines if an arry is sorted
 * in its first pass.
 ****** */

#define SIZE 5

int main() {
    int i,j,temp,swap;
    int theData[SIZE] = {89, 68, 17, 45, 37};
    for(i=0; i<SIZE - 1; i++) {
	swap = 0;
        for(j=0; j < SIZE - i; j++) {
            if(theData[j] > theData[j+1]) {
                temp = theData[j];
	        theData[j] = theData[j+1];
		theData[j+1] = temp;
        	swap = 1;
            }
	}
	if(i == 0 && swap == 0) {
            printf("Array is sorted after the first pass.\n");
	    break;
        }
	if(i != 0 && swap == 0) {
	    printf("Array is not sorted after the first pass.\n");
	}
	if(swap == 0) {
            break;
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", theData[i]);
    }
    printf("\n");

}

