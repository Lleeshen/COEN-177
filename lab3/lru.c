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

/*
 * Return the index of the array that is the mininum value
 */
int findMin(int *intarr, int arrSize) {
    int i;
    int min = intarr[0];
    int minIndex = 0;
    for(i = 1; i < arrSize; ++i) {
        if(min > intarr[i]) {
            min = intarr[i];
            minIndex = i;
        }
    }
    return minIndex;

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
     * Set up Page Table array and Recency Table array
     * Temp variable will be page numbers taken from input
     */
    int numEntries = 0;
    int pageFaults = 0;
    int pageTable[pageSize];
    int recencyTable[pageSize];
    int temp;
    for(temp = 0; temp < pageSize; ++temp) {
        pageTable[temp] = -1;
        recencyTable[temp] = temp - pageSize;
    }

    int status = 1;
    int i = 0;
    int j;
    int k;

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
             * Page Fault if page number is not found
             */
            ++pageFaults;
            printf("%d\n",temp);
            /*
             * Find the page that is oldest in being seen
             */
            k = numEntries;
            if(numEntries >= pageSize) {
                k = findMin(recencyTable,pageSize);
            }
            /*
             * Change that page to the new page
             * Update the age of the page
             */
            pageTable[k] = temp;
            recencyTable[k] = numEntries;
        } else {
            /*
             * Update age of found page
             */
            recencyTable[j] = numEntries;
        }
    }
    fprintf(stderr,"There were %d entries and %d page faults.\n",numEntries,pageFaults);

    exit(0);
}
