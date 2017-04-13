#include <stdlib.h>   //calling libraries
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define MAXLEN 81

struct sort_name {
  char name[100][100];
  char  values[100];
};

void crt_function(FILE * , FILE *);
void list_function(FILE * , FILE *);
int main(int args, char *argv[]) {   //calling files and options


    FILE* fin, *fout;          //how c will retrieve the files into the program
    char line[100];                   // to edit the lines in the input file by retrieving them
    char flag[4];                    // holds flag (option), edit here if you need to change it
    char input[30];
    char output[30];
    
    
    strcpy(flag,argv[1]);
    if ((fin = fopen(argv[2], "r")) == NULL) {     //check statements for file handling
        
        printf("Could not open file %s for reading.\n", argv[2]);
        exit(1);
        
      }
      
    else if ((fout = fopen(argv[3], "w")) == NULL) {
        
        printf("Could not open file %s for writing.\n", argv[3]);
        exit(1);
        
      }
      
      
    if(strcmp(flag,"-l")== 0) {       //conditional to print number list
      printf("%s\n", argv[1]);
      printf("%s\n", argv[2]);
      

        list_function(fin, fout);
        fclose(fin);                 // crt_function doesnt need it since its the last thing the file receives,
        fclose(fout);               // placed the close statements in the function
  
    }
    
    else if(strcmp(flag,"-c")== 0) {

        crt_function(fin, fout);
    }
      
    else if(strcmp(flag,"-b")== 0) {
      

        list_function(fin, fout);
        fputs("\n", fout);
        fputs("\n", fout);
        fseek(fin,0L, SEEK_SET);
        crt_function(fin, fout);
    }
  
}

void list_function(FILE * finput, FILE *foutput) {
          int x = 1;
          char  line[MAXLEN];
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

void crt_function(FILE * finput, FILE *foutput) {
      int x =0;
      char count[100][100];
      char identifier[100][100];
      int y =0;
      int z =0;
      struct sort_name organizer[100];
      char * title = " Cross Reference table";      //as required in assignment
      char * header = "     Identifier      Definition      Use";
      char  line[MAXLEN];
      fputs(title,foutput);
      fputs("\n",foutput);
      fputs("\n",foutput);
      fputs(header,foutput);
      fputs("\n",foutput);
      fputs("\n",foutput);
      
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
                  while(token[y] != NULL) {     //places the variable insides the line and compare string
                      //identifier[z][y] = token[y];
                      organizer[z].name[z][y] = token[y];
                      organizer[z].values[y] = token[y];
                      y++;
                      
                  }
                  
                  
                  y = 0;
                  //while (token != NULL){
                  //fputs("       ",foutput);

                  
                  
                  int length = snprintf( NULL, 0, "%d", x );
                  char* str = malloc( length + 1 );
                  snprintf( str, length + 1, "%d", x );
                  int start = strlen(token);
                  while(start != 20){                   //loop that format the lines
                      organizer[z].values[start] = ' ';
                      start++;
                  }

                  while(str[y] != NULL) {
                    organizer[z].values[start+y] = str[y];
                    y++;
                  }
                  strcat(organizer[z].values,"        ");
                  //printf("%d\n",strlen(organizer[z].values));
                  //printf("%s\n",organizer[z].values);
                  free(str);
                  z++;
                  y = 0;

                }
            }
        }
        
        int i = 0;
        int w = 0;
        while( i != x) {                         //loop to get were variable is used
          while (strlen(organizer[w].name[w]) != 0) {
            if (strstr(count[i],organizer[w].name[w])) {

               int length = snprintf( NULL, 0, "%d", i );
               char* str = malloc( length + 1 );
               snprintf( str, length + 1, "%d", i );
               strcat(organizer[w].values," ");
               strcat(organizer[w].values,str);
               free(str);
      //printf("%s\n",organizer[w].values);
            
            }
            w++;
          }
          w =0;
          i++;
          }
      //printf("%s",organizer[0].values);
    
    int g =0;
    puts("hit a bug bad check");
    
    // while (strcmp(organizer[g].values," ") != 0) {
    while(strlen(organizer[g].values) != 0) {
      puts("starting to assign things");

      int u = 0;       //used to go through the struct array to go through variable matches
      int h = 0;       //newline removal counter
      //printf("%s",line);
      int k =0;         //word strip counter of line for strcmp to refer the line to the variable
      
      char * puller; // this made sure strcmp had the complete word to check
      // while(organizer[g].values[k] != ' '){
      //   section[k] = organizer[g].values[k];
      //   k++;
      // }
      puller = organizer[g].values;
      char section[100] = "\0";
      while(puller[k] != ' '){
        section[k] = puller[k];
        k++;
      }

      printf("stripped first word from line %s\n", section);
      puts("got the section");
      //printf("THIS IS THE SECTION %s\n",section);
      //printf("THIS IS THE LINE WERE WOrking with %s\n",line);
      while(puller[h] !=NULL){
        if(puller[h] == '\n') {  //this removes the newline so we can add the use values later
          puller[h] = 0;
        }
        h++;
      }
      puts("there should be no newline");
      
      //printf("THIS is the after edit %s\n",line);
      
      
      while( strlen(organizer[u].values) != 0) {
        puts("checking off these strings");
        if (strcmp(section,organizer[u].name[u]) == 0) {
              puts("so the organizer name string knows when to end");
              //printf("%s\n",line);

              fputs("      ",foutput);
              fputs(organizer[g].values,foutput);
              puts("so i wrote to the file");
              // while(start != 0){
              //   fputs(" ",foutput);
              //   start++;
              // }


              puts("found my  problem");
              fputs("\n",foutput);
              break;
          
        
      }
      u++;
      }

      
    g++;
    }
      
      
      
    fclose(finput);
    fclose(foutput);
      
}

  