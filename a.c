#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[100];

    // Open the input file in read mode
    inputFile = fopen("hello.haira", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    // Open the output file in write mode
    outputFile = fopen("hello.c", "w");
  
    if (outputFile == NULL) {
        printf("Error creating the output file.\n");
        fclose(inputFile);
        return 1;
    } 
    fprintf(outputFile,"#include<stdio.h>\n");
    fprintf(outputFile,"int main(){\n");

    // Read lines from the input file
    while (fgets(line, sizeof(line), inputFile)) {
        // Remove trailing newline character, if present
        size_t lineLength = strlen(line);
        if (lineLength > 0 && line[lineLength - 1] == '\n') {
            line[lineLength - 1] = '\0';
        }

        // Modify the line based on the specified changes
        if (strcmp(line, "var: 2 plus 3") == 0) {
            fprintf(outputFile, "int var = 2 + 3;\n");
        } else if (strcmp(line, "print-> var") == 0) {
            fprintf(outputFile, "printf(\"%%d\", var);\n}");
        } else {
            // If the line doesn't match any changes, write it as is
            fprintf(outputFile, "%s\n", line);
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File modified and saved successfully.\n");

    return 0;
}

