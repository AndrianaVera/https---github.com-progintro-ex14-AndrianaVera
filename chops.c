#include <stdio.h>
#include <stdlib.h>

/*Function to calculate the number of ways to eat chops*/
int calculateWays(int chops_steak) 
{
    if (chops_steak < 3)
    {
        fprintf(stderr, "I would never order less than 3 chops.\n"); /* error message*/
        exit(1);
    }
    
    /*Initializing counts for the above*/
    int first_chops=1, second_chops=2, third_chops=3

    /*Calculate the number of ways in repeat */
    for (int i = 4; i <= chops_steak; i++)
    {
        int current = first_chops + second_chops + third_chops;
        first_chops = second_chops;
        second_chops = third_chops;
        third_chops = current;
    }

    return third_chops;
}

int main(int argc, char *argv[]) 
{
    /*Check if the number of arguments is exactly 2*/ 
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <number_of_chops_steak>\n", argv[0]);
        return 1; /*exit with error code*/ 
    }



    /*print the result*/
    printf("There are %lld different ways to eat %d chops.\n");

    return 0; 
}
