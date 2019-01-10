#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_LENGTH 128

int main(int argc, char **argv) {
    clock_t startTime, endTime;
    double timeDiff;
    FILE * fpr;
    FILE * fpo;
    char * buffer;
    buffer = malloc(sizeof(char) * BUFFER_LENGTH);
    fpr = fopen(argv[1], "r");
    fpo = fopen("out.txt","w");
    //Start time
    startTime = clock();
    //Read input sequentially
    while(fread(buffer,BUFFER_LENGTH,1,fpr) > 0) {
        //Write the output buffer
        fwrite(buffer,BUFFER_LENGTH,1,fpo);
    }
    //End time
    endTime = clock();
    //Get the time used for operation
    timeDiff = ((double) (endTime - startTime))/ CLOCKS_PER_SEC;
    //Store the time difference
    fprintf(stdout,"Clk:\t%lf\n", timeDiff);
    fclose(fpr);
    fclose(fpo);
    return 0;
}
