/* Lyman Shen
 * COEN 177 Lab 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int arc, char *argv[]) {
    // Display Hello World
    printf("Hello World\n");
    //Print an integer entered by a user
    int in1;
    printf("Enter an integer:\n");
    scanf("%d",&in1);
    printf("You entered %d\n",in1);
    //Add two integers entered by a user
    int in2, in3;
    printf("Enter two integers:\n");
    scanf("%d",&in2);
    scanf("%d",&in3);
    int o1 = in2 + in3;
    printf("The sum is %d\n",o1);
    //Multiply 2 floating point entered by a user
    printf("Enter two numbers:\n");
    double in4, in5;
    scanf("%lf ",&in4);
    scanf("%lf", &in5);
    double o2 = in4 * in5;
    printf("The product is %lf\n",o2);
    //Swap 2 numbers entered by user
    int in6, in7;
    int v1;
    printf("Enter two integers:\n");
    scanf("%d", &in6);
    scanf("%d", &in7);
    printf("The original numbers are %d and %d\n",in6,in7);
    v1 = in6;
    in6 = in7;
    in7 = v1;
    printf("Now the numbers are %d and %d\n",in6,in7);
    //Check a number entered by user is odd or even
    int in8;
    printf("Enter an integer:\n");
    scanf("%d", &in8);
    int o3 = in8 % 2;
    if(o3 == 1)
        printf("The input is odd\n");
    else
        printf("The input is even\n");
    //Check if a character entered by user is vowel or consonant
    char in9;
    printf("Enter a character:\n");
    scanf(" %c",&in9);
    if(!isalpha(in9))
        printf("The character is not vowel or consonant\n");
    else {
        switch(in9) {
            case 'a' :
            case 'A' :
            case 'e' :
            case 'E' :
            case 'i' :
            case 'I' :
            case 'o' :
            case 'O' :
            case 'u' :
            case 'U' :
                printf("The character is a vowel\n");
                break;
            default :
                printf("The character is a consonant\n");
        }
    }
    //Find the largest among three numbers entered by user
    int in10, in11, in12;
    int o4;
    printf("Enter three integers:\n");
    scanf("%d",&in10);
    scanf("%d",&in11);
    scanf("%d",&in12);
    o4 = in10 > in11 ? in10 : in11;
    o4 = o4 > in12 ? o4 : in12;
    printf("The largest number is %d\n",o4);
}
