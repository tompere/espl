  #include <stdio.h>
  #include <string.h>
  #include "bclib.h"

  int main(int argc, char **argv) {
    
    int i;
    int j;
    int k;
    // 1. build our working arrays
    int input[BC_WIDTH] = {0};
    int charsArray[BC_WIDTH][BC_NBITS] = {0};

    int index = 0;
    for(i=1; i!=argc; ++i) {
      // for each word
      for (j=0; j < strlen(argv[i]); j++){
	input[index] = argv[i][j];
	index++;
      }
      // add space, if it's NOT the last word
      if ( i != argc-1 ) {
	input[index] = ' ';
      }    
    }
    
    //coding each char into bits
    for (k=0; k < BC_WIDTH; k++){
      *charsArray[k] = bc_char2bits(input[k],charsArray[k]);
    }
    
    //print
    for (i=0; i<BC_NBITS; i++){
      for (j=0; j<BC_WIDTH; j++){
	if (charsArray[j][i] == 1) {printf('#');}
	else {printf(" ");}
      }
      printf("\n");
    }
    
    return 0;
  }
