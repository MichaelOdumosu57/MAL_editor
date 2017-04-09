#include <stdlib.h>   //calling libraries
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define MAXLEN 81

int main(int args, char *argv[]) {   //calling files and options

    FILE* finput, *foutput;          //how c will retrieve the files into the program
    char line[100];                   // to edit the lines in the input file by retrieving them
    char flag[4];                    // holds flag (option), edit here if you need to change it
    char input[30];
    char output[30];
    
    
    strcpy(flag,argv[1]);
    if(strcmp(flag,"-l")== 0) {       //conditional to print number list
      printf("%s\n", argv[1]);
      printf("%s\n", argv[2]);
      
      if ((finput = fopen(argv[2], "r")) == NULL) {     //check statements for file handling
        
        printf("Could not open file %s for reading.\n", argv[2]);
        exit(1);
        
      }
      
      else if ((foutput = fopen(argv[3], "w")) == NULL) {
        
        printf("Could not open file %s for writing.\n", argv[3]);
        exit(1);
        
      }
      
      else {
          int x = 1;
          while (fgets(line, MAXLEN, finput) != NULL) {
              
              int length = snprintf( NULL, 0, "%d", x );
              char* str = malloc( length + 1 );
              snprintf( str, length + 1, "%d", x );
              strcat(str , "  ");
              strcat(str , line);
              fputs(str, foutput);
              x++;
              free(str);
          }
          
      }
      
      
    }
    
    else if(strcmp(flag,"-c")== 0) {
      printf("%s\n", argv[1]);
    }
    
    else if(strcmp(flag,"-b")== 0) {
      printf("%s\n", argv[1]);
    }
  
}