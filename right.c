#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    /*Check if the number of arguments is at least 2*/
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s <target_calories> <calories_of_dishes...>\n", argv[0]); /* error message*/
        return 1; /*exit with error code 1*/
    }

    /*Convert the target calorie total from string to integer*/ 
    int target_calories = atoi(argv[1]);

    /*checking if the calorie is not negative*/
    if (target_calories <= 0) 
    {
        fprintf(stderr, "Error: Target calorie total must be a positive integer\n"); /* error message*/
        return 1; /*exit with error code 1*/
    }

    int num_dishes = argc - 2; /*Number of dishes is the total arguments minus 2 (target_calories and program name)*/ 
    int total_calories = 0;
    int max_dishes = 0;

    /* Loop for each dish calorie*/
    for (int i = 2; i < argc; i++) 
    {
        /* Converting the calorie count from string to integer*/
        int calories = atoi(argv[i]);

        /*checking if the calorie is not negative*/
        if (calories <= 0) 
        {
            fprintf(stderr, "Error: Calories of each dish must be positive integers\n"); /* error message*/
            return 1; /*exit with error code 1*/
        }

        /*Adding the calorie count of the current dish to the total calories*/
        total_calories += calories;

        /*If the total calories exceed the target, break the loop*/ 
        if (total_calories > target_calories) 
        {
            break;
        }

        /*Increasing the number of dishes that can be eaten*/
        max_dishes++;
    }

    /* Print the result*/
    printf("Within %d calories we can fit %d different dishes\n", target_calories, max_dishes);

    return 0; 
}