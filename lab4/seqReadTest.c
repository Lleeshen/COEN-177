#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_LENGTH 128

int main(int argc, char **argv) {
    clock_t startTime, endTime;
    double timeDiff;
    FILE * fp;
    //Make a character buffer
    char * buffer;
    buffer = malloc(sizeof(char) * BUFFER_LENGTH);
    fp = fopen(argv[1], "r");
    //Start time
    startTime = clock();
    //Read the file sequentially
    while(fread(buffer,BUFFER_LENGTH,1,fp) > 0);
    //End time
    endTime = clock();
    //Get time used for operation
    timeDiff = ((double) (endTime - startTime))/ CLOCKS_PER_SEC;
    //Store the clock time
    fprintf(stdout,"Clk:\t%lf\n", timeDiff);
    fclose(fp);
    return 0;
}
