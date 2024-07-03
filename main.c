#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// inlezen tekst doc
// optellen aantal karakters
// tijd bijhouden
// optimaliseren

void character_counter(filename)
{

    FILE *file = fopen(filename, "r");

    //if (file == NULL)
    //{
    //    printf("Error: could not open file %s", filename);
    //    return 1;
    //}

    char buffer[1000]; // Initialize a char array named 'buffer' with size of 1000

    int counter;
    int i = 0, c; // c is the intermediate variable, i is the increment variable
    while ((c = fgetc(file)) != EOF)
    { // Read contents until it reach the end of the file
        buffer[i] = c;
        i++;
        if (isspace(c))
        {
            ;
        } else {
            counter++;
        }

    }

    // close the file
    fclose(file);

    // Print the character array
    // printf("%i", i);

    // Free the dynamically allocated buffer
    free(buffer);
}

int main(int argc, char *argv[])
{

    char filename = argv[1];
    // Calculate the time taken by character_counter()
    clock_t t;
    t = clock();
    character_counter(filename);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("character_counter() took %i seconds to execute \n", time_taken);

    return 0;
}
