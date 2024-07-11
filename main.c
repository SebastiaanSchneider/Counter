#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// inlezen tekst doc
// optellen aantal karakters
// tijd bijhouden
// optimaliseren

// gcc main.c
// ./main test2.txt

void counter(FILE* file, char* filename)
{
    printf("Second check: %s\n", filename);

    // Character counter (result)
    int alnum_count = 0;
    int alpha_count = 0;
    int upper_count = 0;
    int lower_count = 0;
    int digit_count = 0;
    int space_count = 0;
    int punct_count = 0;

    // To store a character read from file
    char c;

    // Extract characters from file and store in character c
    for (c = getc(file); c != EOF; c = getc(file))
    {
        if (isalnum(c))
        {
            alnum_count++;
            if (isalpha(c))
            {
                alpha_count++;
                if (islower(c))
                {
                    lower_count++;
                } else
                {
                    upper_count++;
                };
            } else
            {
                digit_count++;
            };
        } else if (isspace(c))
        {
            space_count++;
        } else
        {
            punct_count++;
        };
    };

    // Calculate total amount of characters in file
    int total_characters = alnum_count + space_count + punct_count;
    // Print the count of characters
    printf("The file %s has a total of %d characters: %d alphanumerical, of \
which %d alphabetical, of which %d upper case and %d lower case, and %d \
numerical, %d spaces and %d punctuation marks.\n", filename, total_characters,
alnum_count, alpha_count, upper_count, lower_count, digit_count, space_count,
punct_count);
}

// The main program calls counter() and measures time taken by counter()
int main(int argc, char* argv[])
{
    printf("First check: %s %s %s.\n", argv[0], argv[1], "woord");
    // Check if filename is given
    if (argc == 1)
    {
        printf("Error: No file argument given.");
        return 1;
    } else
    {
        char* filename = argv[1];
        // pre-open file
        FILE *file = fopen(filename, "r");

        // Check if file exists
        if (file == NULL)
        {
            printf("Could not open file %s.\n", filename);
        } else
        {
            // Calculate the time taken by counter()
            clock_t t;
            t = clock();
            counter(file, filename);
            t = clock() - t;
            double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

            fclose(file);
            printf("Counter() took %f seconds to execute.\n", time_taken);
            return 0;
        };
    };
}
