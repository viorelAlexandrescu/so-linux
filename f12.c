#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
F12. (1.5 puncte) Scrieti un program care inverseaza ordinea caracterelor
 intr-un fisier al carui specificator este dat ca argument in linia de
 comanda. Nu se vor folosi fisiere auxiliare.
*/

int main(int argc, char **argv) {
    // test arg usage, return 1 if bad
    if (argc != 2) {
        fprintf(stderr, "No file given as argument;\nUsage %s f\n", argv[0]);

        // return bad arg usage error code
        return 1;
    }

    // try to open file, if error, return -1
    FILE *file = fopen(argv[1], "r+");
    if (file == NULL) {
        //fprintf(stderr, "%s", "Could not open file...\n");
	    perror(argv[1]);
        return 10;
    }

    int fileSize;

    // Seek the last byte of the file
    fseek(file, 0, SEEK_END);
    // Offset from the first to the last byte, or in other words, filesize
    fileSize = ftell(file);
     // go back to the start of the file
    rewind(file);

    // check if file has no characters
    if (fileSize == 0) {
        printf("File is empty...\n");

        // return empty file error value
        return 2;
    }

    // iterator
    long i = 0L;
    // first char gets put in last char, in pairs
    char first, last;

    // varianta cu while
    // while (i < fileSize/2) {
    //     // get char according to index position
    //     fseek(file, i, SEEK_SET);
    //     // get pair first element
    //     first = getc(file);

    //     fseek(file, -(i+1), SEEK_END);
    //     // get pair last element
    //     last = getc(file);

    //     // interchange
    //     fseek(file, i, SEEK_SET);
    //     putc(last, file);
    //     fseek(file, -(i + 1), SEEK_END);
    //     putc(first, file);
    //     i++;
    // }

    for(i = 0L; i < fileSize/2; i++) {
        // get char according to index position
        fseek(file, i, SEEK_SET);
        // get pair first element
        first = getc(file);

        fseek(file, -(i+1), SEEK_END);
        // get pair last element
        last = getc(file);

        // interchange
        fseek(file, i, SEEK_SET);
        putc(last, file);
        fseek(file, -(i + 1), SEEK_END);
        putc(first, file);
    }
    
    // close file access
    fclose(file);
    
    // return success code
    return 0;
}
