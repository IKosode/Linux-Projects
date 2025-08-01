#include <stdio.h>
#include <string.h>

/* ******
 * Ike Osode
 * proj# 4
 * This file is used to keep track of the amount of each base in a DNA sequence
 * and their longest runs in a sequence. In order to use the program, one must
 * input a text file consisting of a sequence of DNA bases. 
 ****** */

int main() {
    char curr;
    char prev = '\0';
    int prevReps = 0;
    int gbase = 0;
    int abase = 0;
    int cbase = 0;
    int tbase = 0;
    int numChar = 0;
    int areps = 0;
    int greps = 0;
    int creps = 0;
    int treps = 0;
    curr = getchar();
    prevReps = 0;
    while(curr != EOF) {
	if (curr == prev || curr == prev + 32 || curr == prev - 32) {
            prevReps++;
	}
	else if(curr == ' ' || curr == '\n') {
            prevReps = prevReps;
        }
	else{
            switch (prev) {
                case 'g':
                case 'G':
                    if (prevReps > greps) {
                        greps = prevReps;
                    }
                    break;
                case 'a':
                case 'A':
                    if (prevReps > areps) {
                        areps = prevReps;
                    }
                    break;
                case 'c':
                case 'C':
                    if (prevReps > creps) {
                        creps = prevReps;
                    }
                    break;
                case 't':
                case 'T':
                    if (prevReps > treps) {
                        treps = prevReps;
                    }
                    break;
	        case ' ':
		    curr = prev;
		    break;
            }
	    if ((curr != 'a' && curr != 'A' && curr != 'c' && curr != 'C' &&
                 curr != 'g' && curr != 'G' && curr != 't' && curr != 'T' &&
                 curr != ' ' && curr != '\n')) {
                return 1; 
            }
	    prev = curr;
	    prevReps = 1;

            
        }
	    
        switch(curr) {
	    case 'g':
	    case 'G':
	        gbase++;
		numChar++;
		break;
        
	    case 'a':
	    case 'A':
                abase++;
		numChar++;
                break;
            case 'c':
	    case 'C':
                cbase++;
		numChar++;
                break;
            case 't':
	    case 'T':
                tbase++;
		numChar++;
		break;
        }
        curr = getchar();

    }
    switch (prev) {
        case 'g':
        case 'G':
            if (prevReps > greps) greps = prevReps;
            break;
        case 'a':
        case 'A':
            if (prevReps > areps) areps = prevReps;
            break;
        case 'c':
        case 'C':
            if (prevReps > creps) creps = prevReps;
            break;
        case 't':
        case 'T':
            if (prevReps > treps) treps = prevReps;
            break;
    }//only keep track of amt of times bases appear
    printf("The DNA sequence has %d bases\n",numChar);	
    printf("%6.2f%% of the bases are A and its longest run has %d repetitions\n"
		    , (float)abase/numChar * 100, areps);
    printf("%6.2f%% of the bases are C and its longest run has %d repetitions\n"
		    , (float)cbase/numChar * 100, creps);
    printf("%6.2f%% of the bases are G and its longest run has %d repetitions\n"
		    , (float)gbase/numChar * 100, greps);
    printf("%6.2f%% of the bases are T and its longest run has %d repetitions\n"
		    , (float)tbase/numChar * 100, treps);
    return 0;

}
