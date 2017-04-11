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
    if ((finput = fopen(argv[2], "r")) == NULL) {     //check statements for file handling
        
        printf("Could not open file %s for reading.\n", argv[2]);
        exit(1);
        
      }
      
    else if ((foutput = fopen(argv[3], "w")) == NULL) {
        
        printf("Could not open file %s for writing.\n", argv[3]);
        exit(1);
        
      }
      
      
    if(strcmp(flag,"-l")== 0) {       //conditional to print number list
      printf("%s\n", argv[1]);
      printf("%s\n", argv[2]);
      

      
          int x = 1;
          while (fgets(line, MAXLEN, finput) != NULL) {
              //printf(" %d     %d\n",x,strlen(line));
              if (strlen(line) != 1) {
                
                int length = snprintf( NULL, 0, "%d", x );
                char* str = malloc( length + 1 );
                snprintf( str, length + 1, "%d", x );
                strcat(str , "  ");
                strcat(str , line);
                fputs(str, foutput);
                x++;
                free(str);
                
              }
              else {
                fputs(line, foutput);
              }
          
          
      }
      
      
    }
    
    else if(strcmp(flag,"-c")== 0) {
      fputs( "Cross Reference table\n", foutput);
      char * header = "     Identifier      Definition      Use";
      fputs(header,foutput);
      int x =0;
      char count[100][100];
      char identifier[100][100];
      int y =0;
      int z =0;
      
        
      
        while (fgets(line, MAXLEN, finput) != NULL) {
            
            if (strlen(line) != 1) {
              
                x++;
                char use[23];
                if(isspace(line[27]) == 0){
                  
                  strncpy(use,  line + 26, 43 -26);
                  int y = 0;
                  while(use[y] != NULL) {
                      count[x][y] = use[y];
                      y++;
                  }
                  
                  //printf("%s",count[x]);
                  
                }
          
                if (line[0] != '#' && isspace(line[0])  == 0  ) {
                  //printf("%c\n", line[0]);
                  
                  const char stop[2] =":";
                  char * token;
                  token = strtok(line,stop);
                  
                  y = 0;
                  while(token[y] != NULL) {
                      identifier[z][y] = token[y];
                      y++;
                      
                  }
                  z++;
                  y = 0;
                  //while (token != NULL){
                  fputs("\n",foutput);
                  fputs("       ",foutput);
                  fputs(token,foutput);
                  int length = snprintf( NULL, 0, "%d", x );
                  char* str = malloc( length + 1 );
                  snprintf( str, length + 1, "%d", x );
                  int start = strlen(token) + 8;
                  while(start != 26){
                      fputs(" ",foutput);
                      start++;
                  }
                  fputs(str,foutput);
                  free(str);
                  //printf("%c\n",line[26]);


                    //printf("%s",token);
                    // if (strstr(use,token) ){
                    //   strcat(count,str);
                    //   }
                    
                
                  
                  
                
                    //token = strtok(NULL, stop);
                  
                  //fputs(line,foutput);
                }
            }
        }
        int i = 0;
        int w = 0;
        while( i != 25) {
          while (w != 9) {
            if (strstr(count[i],identifier[w])) {
               printf("%s index %d: line %d\n", identifier[w], w, i);
            }
            w++;
          }
          w =0;
          i++;
          }
        
        

        //printf("%s\n",use);
    }
      
    
    
    
    else if(strcmp(flag,"-b")== 0) {
      printf("%s\n", argv[1]);
    }
  
}