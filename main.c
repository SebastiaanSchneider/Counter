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


void counter(char *filename)
{
    printf("second check: %s\n", filename);
    FILE* fp;

    // Character counter (result)
    int count = 0;

    // To store a character read from file
    char c;

    // char filename[1024] = "test.txt";
    // Open the file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s\n", filename);
    } else
    {
        // Extract characters from file
        // and store in character c
        for (c = getc(fp); c != EOF; c = getc(fp))

            // Increment count for this character
            if (isalpha(c))
            {
                continue;
            } else
            {
                count++;
            };

        // Close the file
        fclose(fp);

        // Print the count of characters
        printf("The file %s has %d characters\n ", filename, count);
    };
}

// The main program calls counter() and measures time taken by counter()
int main(int argc, char *argv[])
{
    printf("first check: %s %s %s\n", argv[0], argv[1], "woord");
    // Check if filename is given
    if (argc == 1) {
        printf("Error: No file argument given");
        return 1;
    } else {
        // Calculate the time taken by counter()
        clock_t t;
        t = clock();
        counter(argv[1]);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

        printf("counter() took %f seconds to execute \n", time_taken);
        return 0;
    };
}
