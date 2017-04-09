#include <stdlib.h>   //calling libraries
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int main(int args, char *argv[]) {   //calling files and options

  
  
    if(strcmp(argv[1],"-l")== 0) {
      printf("%s\n", argv[1]);
      printf("%s\n", argv[2]);
    }
    
    else if(strcmp(argv[1],"-c")== 0) {
      printf("%s\n", argv[1]);
    }
    
    else if(strcmp(argv[1],"-b")== 0) {
      printf("%s\n", argv[1]);
    }
  
}