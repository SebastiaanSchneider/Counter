#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// inlezen tekst doc
// optellen aantal karakters
// tijd bijhouden
// optimaliseren

// ./main test2.txt

void character_counter(char filename) {

    FILE* file = fopen(filename, "r");

    // Print error if no usable file
    if (file == NULL) {
       printf("Error: could not open file %s", filename);
    };

    char buffer[1000]; // Initialize a char array named 'buffer' with size of 1000

    int counter;
    int i = 0, c; // c is the intermediate variable, i is the increment variable
    while ((c = fgetc(file)) != EOF) { // Read contents until it reach the end of the file
        buffer[i] = c;
        i++;
        if (isspace(c))
        {
            ;
        } else {
            counter++;
        }
    };

    // Close the file
    fclose(file);

    // Print counter
    printf("Count is %i", counter);

    // Print the character array
    // printf("%i", i);

    // Free the dynamically allocated buffer
    // free(buffer);
}

int main(int argc, char *argv[]) {
    // Check if filename is given
    if (argv[1] == NULL) {
        printf("Error: No file argument given");
        return 1;
    } else {
        // Get filename from input
        char filename = argv[1];

        // Calculate the time taken by character_counter()
        clock_t t;
        t = clock();
        character_counter(filename);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

        printf("character_counter() took %i seconds to execute \n", time_taken);

        return 0;
    };
}
