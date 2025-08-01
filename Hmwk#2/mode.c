#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file finds the mode within a list of 100 values.
 ****** */

#define SIZE 100

int main() {
    int nums[SIZE] = {
        5, 5, 5, 5, 5, 5, 7, 5, 5, 2, 9, 5, 2, 1, 4, 7, 8, 2, 3, 9, 4, 2, 1, 6,
	3, 7, 9, 1, 6, 2, 7, 1, 8, 3, 4, 1, 8, 6, 2, 9, 8, 5, 5, 1, 7, 3, 2, 8, 
	9, 4, 1, 4, 7, 6, 3, 4, 5, 7, 1, 3, 2, 8, 4, 5, 6, 9, 1, 4, 2, 6, 7, 8,
	9 ,5, 7, 2, 6, 4, 8, 6, 1, 9, 2, 4, 7, 3, 5, 2, 1, 3, 9, 6, 5, 4, 2, 8,
       	3
    };
    int value = 0, max = 0, i, j;
    for(i = 0; i<SIZE;i++) {
        int count = 0;
	for(j = 0; j<SIZE;j++) {
	    if(nums[j] == nums[i]) {
	       count++;
	    }
        }
	if(count > max) {
	    max = count;
	    value = nums[i];
	}
    }
    printf("Mode: %d", value);
    return 0;
}
