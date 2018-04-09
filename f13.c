#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
F13. (0.5 puncte) Scrieti un program care numara aparitiile unui caracter
 intr-un fisier dat. Caracterul si specificatorul fisierului sunt dati ca
 argumente in linia de comanda.
*/
const char *badArgMessage = "\nBad arguments...\nUsage: $ ./f13 c f\nWhere c is the char whose appearances are counted in file f\n";

int main(int argc, char **argv) {
    // test arg usage, return -1 if bad
    if (argc != 3) {
        fprintf(stderr, "%s", badArgMessage);
        return -1;
    }

    // test char arg, return -1 if bad
    if (strlen(argv[1]) > 1) {
        fprintf(stderr, "%s", badArgMessage);
        return -1;
    }

    // try to open file
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Could not open file...\n");
    } else {
        
        // get first argument value
        char c = argv[1][0];
        int charCount = 0;
        
        int currentChar;
        /* read one character at a time from file, stopping at EOF, which
           indicates the end of the file.  Note that the idiom of "assign
           to a variable, check the value" used below works because
           the assignment statement evaluates to the value assigned. */
        while ((currentChar = (char)fgetc(file)) != EOF) {
            if(currentChar == c)
                charCount++;
        }
        
        fclose(file);

        if(charCount > 1)
            printf("\nDone!\nYour char (%c) was found %i times\n\n" , c, charCount);
        else
            printf("\nDone!\nYour char (%c) was found %i time\n\n" , c, charCount);
        // return number of chars
        return charCount;
    }
}