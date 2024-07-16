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
    int lower_count = 0;
    int space_count = 0;
    int punct_count = 0;
    int upper_count = 0;
    int digit_count = 0;
    int other_count = 0;

    int manual_all_count = 0;

    // To store a character read from file
    char c;

    // Extract characters from file and store in character c
    for (c = getc(file); c != EOF; c = getc(file))
    {
        manual_all_count++;
        if (islower(c))
        {
            lower_count++;
        } else if (isspace(c))
        {
            space_count++;
        } else if (ispunct(c))
        {
            punct_count++;
        } else if (isupper(c))
        {
            upper_count++;
        } else if (isdigit(c))
        {
            digit_count++;
        } else
        {
            other_count++;
            // if (other_count % 10000 == 0)
            // {
            //     printf("other: %c\n", c);
            // };
        };
    };

    // Calculate total amount of characters in file
    int alpha_count = lower_count + upper_count;
    int alnum_count = alpha_count + digit_count;
    int total_characters = alnum_count + space_count + punct_count;
    int all_count = total_characters + other_count;
    // Print the count of characters
    printf("The file %s has a total of %d characters: %d alphanumerical, of \
which %d alphabetical, of which %d upper case and %d lower case, and %d \
numerical, %d spaces and %d punctuation marks.\nThere are also %d other \
characters, for a total 'thing' count of %d. Manual all is %d.\n", filename,
total_characters, alnum_count, alpha_count, upper_count, lower_count,
digit_count, space_count, punct_count, other_count, all_count);
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
