#include <stdio.h>
// the program print in an invert order the args

int main(int argc, char **argv){
    int i;
    for (i = (argc -1); i > 0; i--){
      printf("%s ",argv[i]);
    }
    return 0;
  }
