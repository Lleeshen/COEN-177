
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char * argv){
    pid_t p1, p2, p3;
    int layer;
    int status;
    
    printf("Original is %d\n",getpid());

    p1 = 0;                                                                     //Initialize variables so code enters the main loop
    p2 = 0;
    p3 = 0;

    layer = 0;

    while(layer < 2 && (p1 == 0 || p2 == 0 || p3 == 0)) {                       //Loop to make sure only the most recent children processes created fork more children
        p1 = fork();
        if(p1 == 0) {
            printf("Child is %d, Parent is %d\n",getpid(),getppid());           //Test creation of first new child
            while(waitpid(-1, &status, 0) != -1);                               //Make sure all children processes die before parent
        } else if (p1 > 0) {
            p2 = fork();
            if(p2 == 0) {
                printf("Child is %d, Parent is %d\n",getpid(),getppid());       //Test creation of second new child
                while(waitpid(-1, &status, 0) != -1);                           //Make sure all children processes die before parent
            } else if (p2 > 0) {
                p3 = fork();
                if (p3 == 0) {
                    printf("Child is %d, Parent is %d\n",getpid(),getppid());   //Test creation of third new child
                    while(waitpid(-1, &status, 0) != -1);                       //Make sure all children processes die before parent
                }
            }
        }

        layer ++;
    }
                            
    while(waitpid(-1,&status,0) != -1);                                         //Make sure all forked processes of original die before original
    return 0;
}
