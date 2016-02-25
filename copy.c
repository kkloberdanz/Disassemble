/*
 * Programmer     : Kyle Kloberdanz
 * File           : copy.c
 * Date Created   : 25 Feb 2016
 *
 * Description    : Reads in a file as a binary, and copies that file
 *                  to another file
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    const int BUFFER_SIZE = 1; // default buffer size
    char* inputFileName;
    char* outputFileName;

    if (argc < 3) {
        puts("decompile: too few arguments");
        exit(EXIT_FAILURE);
    } else if (argc > 3) {
        puts("decompile: too many arguments");
        exit(EXIT_FAILURE);
    } else {
        inputFileName  = argv[1];
        outputFileName = argv[2];
    }

    FILE* inputFile, *outputFile;

    if ( !(inputFile  = fopen(inputFileName, "rb")) ){
        printf("%s %s\n", "decompile: unable to open file", 
                inputFileName);
        exit(EXIT_FAILURE);
    }
    outputFile = fopen(outputFileName, "wb");

    unsigned char buffer[BUFFER_SIZE];
    while ( fread(buffer, sizeof(buffer), 1, inputFile) ) {
        fwrite(buffer, sizeof(buffer), 1, outputFile);
        (*buffer <= 0xF)?   printf("0%0X ", *buffer) :
                           printf("%0X " , *buffer);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
