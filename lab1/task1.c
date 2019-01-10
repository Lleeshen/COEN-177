
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv) {
    char input[20];                                     //Use this as shell input
    char exitCon[5] = "exit";                           //Exit code is stored
    int status;                                         //Dummy variable
    pid_t pid;                                          //Process ID variable

    while(1) {
        scanf("%s",input);                              //Get input
        if(strcmp(input, exitCon) == 0) {               //If input is "exit"
            return 0;                                   //Quit
        } else {                                        //Otherwise create new process
            pid = fork();
            if(pid != 0) {
                waitpid(-1,&status,0);                  //Have shell program wait for HelloWorld to finish
            } else {
                execve("helloWorld.out",NULL,NULL);     //Execute HelloWorld program in child process
                printf("Error");                        //Test for error, shouldn't print
            }
        }
    }
}
