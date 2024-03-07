#include <stdio.h>
#include <stdlib.h>

#define MAX_READINGS 100 /*Maximum number of readings*/
#define BUFFER_SIZE 100 /*Buffer size for reading lines from the file*/

struct 
{
    char timestamp[BUFFER_SIZE]; /*Timestamp of the reading*/
    float temperature;
    float distance_from_average;
} Reading;

float calculate_average(Reading readings[], int count);
int compare_temperatures(const void *a, const void *b);

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    /*Opening the file for reading*/
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        return 1;
    }

Reading readings[MAX_READINGS];
    char line[BUFFER_SIZE];
    int count = 0;

    /*Read and parse temperature readings from the file*/
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (sscanf(line, "%[^,],%f", readings[count].timestamp, &readings[count].temperature) != 2) 
        {
            fprintf(stderr, "Error: Invalid input format\n");
            fclose(file);
            return 1;
        }
        count++;
    }

    fclose(file);

    if (count == 0) 
    {
        fprintf(stderr, "Error: No temperature readings found\n");
        return 1;
    }

    return 0;
}



