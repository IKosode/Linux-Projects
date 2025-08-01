#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * hmwk# 2
 * This file performs math operations with an array of a hundred values.
 ****** */

#define SIZE 100

int main() {
    int nums[SIZE] = {
        -3, -4, -2, 5, -7, 5, 7, 5, 5, 2, 9, 5, 2, 1, 4, 7, 8, 2, 3, 9, 4, 2, 1,
       	6, 3, 7, 9, 1, 6, 2, 7, 1, 8, 3, 4, 1, 8, 6, 2, 9, 8, 5, 5, 1, 7, 3, 2,
       	8, 9, 4, 1, 4, 7, 6, 3, 4, 5, 7, 1, 3, 2, 8, 4, 5, 6, 9, 1, 4, 2, 6, 7,
       	8, 9 ,5, 7, 2, 6, 4, 8, 6, 1, 9, 2, 4, 7, 3, 5, 2, 1, 3, 9, 6, 5, 4, 2,
       	8, 3, 1, 2, 9};
    int pcount = 0, ncount = 0, psum = 0, nsum = 0, count = 0;
    for(int i = 0; i < SIZE; i++) {
        if(nums[i] >= 0) {
	    pcount++;
	    psum += nums[i];
	}
        if(nums[i] < 0) {
	    ncount++;
    	    nsum += nums[i];
	}	    
    }
    printf("Array: \n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ",nums[i]);
        count++;
	if(count % 10 == 0) {
            printf("\n");
	}
    }
    printf("Positive:\nCount: %d\nSum: %d\nAverage: %.2f\n",pcount,psum,
		    (float)psum/pcount);
    printf("Negative:\nCount: %d\nSum: %d\nAverage: %.2f",ncount,nsum,
		    (float)nsum/ncount);
    return 0;

}

