#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_LENGTH 128

int main(int argc, char **argv) {
    int randNum;
    long int fileSize, usedSize;
    clock_t startTime, endTime;
    double timeDiff;
    FILE * fp;
    char * buffer;
    buffer = malloc(sizeof(char) * BUFFER_LENGTH);
    fp = fopen(argv[1], "r");
    //Get the file Size
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);
    usedSize = 0;
    srand(time(NULL));
    //Get start time
    startTime = clock();
    //Write the file Size amount of bytes to output
    while(usedSize < fileSize) {
        //Get random byte to read input from
        randNum = rand() % (fileSize - BUFFER_LENGTH);
        while(fseek(fp, randNum, SEEK_SET) != 0);
        //Read input
        fread(buffer,BUFFER_LENGTH,1,fp);
        //Output size is increased
        usedSize += BUFFER_LENGTH;
    }
    //Get end time
    endTime = clock();
    //Get time used for operation
    timeDiff = ((double) (endTime - startTime))/ CLOCKS_PER_SEC;
    //Store time difference
    fprintf(stdout,"Clk:\t%lf\n", timeDiff);
    fclose(fp);
    return 0;
}
