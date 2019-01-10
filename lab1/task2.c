
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char * argv){
    pid_t pid = 0;
    int num_process = 0;
    int status;

    printf("Original is %d\n",getpid());                                //To test the program

    while(num_process < 8 && pid == 0) {                                //Loop to get the most recent children process to make more children
        pid = fork();
        if(pid == 0) {
            printf("Child is %d, Parent is %d\n",getpid(),getppid());   //To test the program
            num_process++;
        } else {
            waitpid(-1,&status,0);                                      //Used to make sure child process dies first
        }
    }

    return 0;
}
