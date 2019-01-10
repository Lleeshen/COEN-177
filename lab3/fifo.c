/*
 * Lyman Shen
 * 10/20/18
 * FIFO Page Replacement Algorithm
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Auxillary search function returns negative number
 * if not found in array, other return index where
 * number is found
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
     * Set up Page Table as a queue implemented as an array
     * Temp variable will be page numbers taken from input
     */
    int numEntries = 0;
    int pageFaults = 0;
    int pageTable[pageSize];
    int temp;
    for(temp = 0; temp < pageSize; ++temp) {
        pageTable[temp] = -1;
    }

    int status = 1;
    int i = 0;
    int j;
    int end;

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
         * Run search to see if item is already in table
         */
        j = search(temp, pageTable, pageSize);
        /*
         * Page fault if returns -1
         */
        if(j == -1) {
            ++pageFaults;
            printf("%d\n",temp);
            /*
             * Set oldest page to the new page and increment
             */
            pageTable[i] = temp;
            //Index i is the oldest stored input before increment
            i = (i + 1) % pageSize;
        }
    }
    fprintf(stderr,"There were %d entries and %d page faults.\n",numEntries,pageFaults);
    exit(0);
}
