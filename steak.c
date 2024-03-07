#include <stdio.h>
#include <stdlib.h>

#define SLASH_UNICODE "\xF0\x9F\xA5\xA9" /*defining the slash unicde for steak*/

int main() 
{
    char line[1000]; /*Getting a maximum line length of 1000 characters*/
    int length;

    /*read lines for stdin until EOF*/
    while (fgets(line, sizeof(line), stdin)) 
    {
        /*check if the line length is exceeding the buffer size*/
        if (line[sizeof(line) - 2] != '\0' && line[sizeof(line) - 2] != '\n') 
        {
            fprintf(stderr, "Error: Input line exceeds buffer size\n"); /*error message*/
            return 1; /*exit with error code 1*/
        }

        /*slash unicode to the beginning of the line*/ 
        printf("%s", SLASH_UNICODE);

        /*Print the rest of the line*/
        printf("%s", line);

        /*slash unicode to the end of the line*/
        printf("%s", SLASH_UNICODE);
    }

    return 0;
}
