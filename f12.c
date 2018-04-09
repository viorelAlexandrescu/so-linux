#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
F12. (1.5 puncte) Scrieti un program care inverseaza ordinea caracterelor
 intr-un fisier al carui specificator este dat ca argument in linia de
 comanda. Nu se vor folosi fisiere auxiliare.
*/
const char *badArgMessage = "\nBad arguments...\nUsage: $ ./f12 f\nWhere f is the text file of which, it's contents shall be reversed\n";

int main(int argc, char **argv) {
    // test arg usage, return 1 if bad
    if (argc != 2) {
        fprintf(stderr, "%s", badArgMessage);
        return 1;
    }

    // try to open file, if error, return -1
    FILE *file = fopen(argv[1], "r+");
    if (file == NULL) {
        fprintf(stderr, "%s", "Could not open file...\n");
        return -1;
    }

    char currentChar;
    int fileSize;

    // Seek the last byte of the file
    fseek(file, 0, SEEK_END);
    // Offset from the first to the last byte, or in other words, filesize
    fileSize = ftell(file);
     // go back to the start of the file
    rewind(file);

    printf("File has %i bytes\n", fileSize);

    long i = 0L;
    while(i < fileSize) {
        fseek(file, i, SEEK_SET);
        printf("\n char:'%c' at position '%ld'", getc(file), ftell(file));
        i++;
    }
    printf("\n");

    
    fclose(file);
    // printf("\nDone!\nThe contents of your file have been reversed!");
    return 0;
}
