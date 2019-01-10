#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_LENGTH 128

int main(int argc, char **argv) {
    int randNum;
    long int fileSize, usedSize;
    clock_t startTime, endTime;
    double timeDiff;
    FILE * fpr;
    FILE * fpo;
    char * buffer;
    buffer = malloc(sizeof(char) * BUFFER_LENGTH);
    fpr = fopen(argv[1], "r");
    fpo = fopen("out.txt", "w");
    fseek(fpr, 0L, SEEK_END);
    //File Size
    fileSize = ftell(fpr);
    usedSize = 0;
    srand(time(NULL));
    //Get start time
    startTime = clock();
    //Make sure output file size is same as input file size
    while(usedSize < fileSize) {
        //Choose random byte for read/write
        randNum = rand() % (fileSize - BUFFER_LENGTH);
        while(fseek(fpr, randNum, SEEK_SET) != 0);
        //Read the buffer from there and write from the buffer
        fread(buffer,BUFFER_LENGTH,1,fpr);
        fwrite(buffer,BUFFER_LENGTH,1,fpo);
        //Update input file size
        usedSize += BUFFER_LENGTH;
    }
    endTime = clock();
    timeDiff = ((double) (endTime - startTime))/ CLOCKS_PER_SEC;
    fprintf(stdout,"Clk:\t%lf\n", timeDiff);
    fclose(fpr);
    fclose(fpo);
    return 0;
}
