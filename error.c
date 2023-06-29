#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[500];
int bufp;

int main(int argc , char *argv[]) {
    FILE *inputFile, *outputFile;
    char line[100];

    if(argc < 2){
    printf("Error: please enter input file name and output file name\n");
    return 1;
    }
    
    // Open the input file from the user
    inputFile = fopen(argv[1], "r");
   

    // Open the output file in write mode
    outputFile = fopen("hello.c", "w");
  
   if (outputFile == NULL) {
        printf("Error creating the output file.\n");
        fclose(inputFile);
        return 1;
    }
    
    // prologue ----------------------------------------------------------------------------
    fprintf(outputFile,"#include<stdio.h>\n");
    fprintf(outputFile,"int main() {\n");
    
    // the parser
    
    switch (bufp) {
    	case "var":
    		fprintf(outputFile,"int var");
    		// fallthrough
    	case ":":
    		fprintf(outputFile,"=");
    		// fallthrough
    	case "->":
    		fprintf(outputFile,"("%d\n",var)");
    		// fallthrough
    	case "print":
    		fprintf(outputFile,"printf");
    		// fallthrough
    	case "plus"
    		fprintf(outputFile,"+");
    		// fallthrough
    	default:
    		printf("Unknown key word\n");
    		return 1; // break
    }
/*
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
            fprintf(outputFile, "printf(\"%%d\", var);\n");
        } else {
            // If the line doesn't match any changes, write it as is
            fprintf(outputFile, "%s\n", line);
        }
    }
*/
    
    // epilogue -------------------------------------------------------------------------
    fprintf(outputFile,"}\n");

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File modified and saved successfully.\n");
   
    system("gcc -o hello hello.c");
   

    return 0;
}

