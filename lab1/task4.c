
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char * argv){
    pid_t p1, p2, p3;
    int layer;
    int status;
    
    printf("Original is %d\n",getpid());
    
    p3 = fork();
    if(p3 == 0) {                                                               //A miscellaneous children process with 2 children to give the difference between children process in main loop and needed children
        printf("Child is %d, Parent is %d\n",getpid(),getppid());
        while(waitpid(-1,&status,0) != -1);
        p1 = fork();
        if (p1 == 0) {
            printf("Child is %d, Parent is %d\n",getpid(),getppid());
            while(waitpid(-1,&status,0) != -1);    
        } else if (p1 > 0) {
            p2 = fork();
            if (p2 == 0) {
                printf("Child is %d, Parent is %d\n",getpid(),getppid());
                while(waitpid(-1,&status,0) != -1);
            }
        }
    
    } else if (p3 > 0) {

        p1 = 0;
        p2 = 0;
        layer = 0;

        while(layer < 3 && (p1 == 0 || p2 == 0)) {                              //Main loop where the newest children processes always create 2 children. This is done 3 times to create 14 children in a binary-tree like structure
            p1 = fork();
            if(p1 == 0) {
                printf("Child is %d, Parent is %d\n",getpid(),getppid());       //Check child 1
                while(waitpid(-1,&status,0) != -1);                             //Make sure parent process waits for all child processes to finish
            } else if (p1 > 0) {
                p2 = fork();
                if(p2 == 0) {
                    printf("Child is %d, Parent is %d\n",getpid(),getppid());   //Check child 2
                    while(waitpid(-1,&status,0) != -1);                         //Make sure parent process waits for all child process to finish
                }
            }
            layer ++;
        }
    }
                            
    while(waitpid(-1,&status,0) != -1);                                         //Make sure original process waits for all other child processes to finish
    return 0;
}
