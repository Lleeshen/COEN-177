/*
 * Lyman Shen
 * 10/20/18
 * LRU Page Replacement Algorithm
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Auxillary search function
 * Returns index of where number is found
 * if it is there
 * If number is not found, return -1
 */
int search(int num, int *intarr, int arrSize) {
    int i;
    for(i = 0; i < arrSize; ++i) {
        if(num == intarr[i]) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    /*
     * Use command line input for pageSize, otherwise defaults to 100
     */
    int pageSize = 100;    
    if(argv[1] != NULL) {
        int temp = atoi(argv[1]);
        if(temp != 0) {
            pageSize = temp;
        }
    }

    /*
     * Initialize number of entries, page faults to 0;
     * Set up Page Table array and Reference Table array
     * Temp variable will be page numbers taken from input
     */
    int numEntries = 0;
    int pageFaults = 0;
    int pageTable[pageSize];
    int refPageTable[pageSize];
    int temp;

    int status = 1;
    int i = 0;
    int j;
    int k;

    for(j=0; j < pageSize; ++j) {
        pageTable[j] = -1;
        refPageTable[j] = -1;
    }

    while(1) {    
        /*
         * If there is no more input, exit infinite loop
         */
        status = scanf("%d", &temp);
        if(status != 1) {
            break;
        }
        /*
         * Increment number of entries
         */
        ++numEntries;
        /*
         * Search for the new page number
         */
        j = search(temp, pageTable, pageSize);
        if(j == -1) {
            /*
             * If page number not found, page fault
             */
            ++pageFaults;
            printf("%d\n",temp);
            /*
             * Find the next page that has reference bit 0
             * If the reference bit is 1, set to 0 and keep searching
             */
            while(refPageTable[i] == 1) {
                refPageTable[i] = 0;
                i = (i+1) % pageSize;
            }
            /*
             * Replace the page with the new page number and set reference to 1
             */
            pageTable[i] = temp;
            refPageTable[i] = 0;
            /*
             * Make the new page the last page to replace when need to replace again
             */
            i = (i+1) % pageSize;
        } else {
            /*
             * Set reference bit if found
             */
            refPageTable[j] = 1;
        }
    }
    fprintf(stderr,"There were %d entries and %d page faults.\n",numEntries,pageFaults);

    exit(0);
}
