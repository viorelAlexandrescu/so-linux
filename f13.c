#include <stdio.h>
#include <stdlib.h>

/*
F13. (0.5 puncte) Scrieti un program care numara aparitiile unui caracter
 intr-un fisier dat. Caracterul si specificatorul fisierului sunt dati ca
 argumente in linia de comanda.
*/

int main(int argc, char **argv {
    // test arg usage, return -1 if bad
    if (argc != 2) {
        printf("Too many arguments...\nUsage: $ f13 c f\nWhere c is the char whose appearances are counted in file f\n");
        return -1;
    }
    else if (argc == 0) {
        printf("No arguments given...\nUsage: $ f13 c f\nWhere c is the char whose appearances are counted in file f\n");
        return -1;
    }

    FILE *file = fopen(argv[2], "r");
    if (f == 0) {
        printf("Could not open file...\n");
    } else {
        // get first argument value
        char c = argv[1][0];
        int argCharAsInt = (int) c;
        int charCount = 0;
        
        int currentChar;
        /* read one character at a time from file, stopping at EOF, which
           indicates the end of the file.  Note that the idiom of "assign
           to a variable, check the value" used below works because
           the assignment statement evaluates to the value assigned. */
        while ((currentChar = fgetc(file)) != EOF) {
            if(argCharAsInt == currentChar)
                charCount++;
        }
        
        fclose( file );

        printf("Done!\nYour char (%c) was found %u times\n" , c, charCount);
        // return number of chars
        return charCount;
    }
}