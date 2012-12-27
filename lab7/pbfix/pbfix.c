#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "diff.h"

static int printMsg = 0; //option m : 0- don;t print, 1- printBytes
static int revDiff = 0; // option r: 0- regular, 2- apply difference by reverse
static char* fileName;

int main(int argc, char *argv[ ]) {
  //recieving all arguments (options and/or input files)
   int c;
   FILE *difference; //input file: differences file, as recieved by bcmp.c
   
   while ((c = getopt(argc, argv, "hrm")) != -1) {  
     switch(c) {
        case 'h':
	  printf("\r\n===== options summery: ======\r\n");
	  printf("-h print a summary of options and exit\r\n");
	  printf("-r reverse the differences\r\n");
	  printf("-m print a message each time a change is applied\r\n");
	  printf("====================\r\n");
	  return 0;
        case 'r':
	  revDiff = 1;
          break;
	case 'm':
	  printMsg = 1;
          break;
	}
    }
    
   fileName = argv[optind];
   difference = fopen(argv[optind+1], "r"); //differences file
   char diffLineBuffer[300]; //buffer differences file line
   struct diff theDiff; //tokenizer of line
   
  // MAIN LOOP
   while(fgets(diffLineBuffer,sizeof(diffLineBuffer),difference) != NULL) // while there is still new lines
   {      
     // tokenize a line into 'theDiff'
      parsediff(diffLineBuffer, &theDiff);
      fix(theDiff, diffLineBuffer);
      printf("%d\n",7);
    }
    fclose(difference);
    return 0;
}

// internal fix function - should be done in parallel

int fix(struct diff chg, char* diffLine){
      
      FILE *toPrint; //input file: original file to fix
      
      // open input file again
      toPrint = fopen(fileName, "rb+");
      
      // go to position in difference file
      fseek(toPrint, chg.offset, SEEK_SET);
      
      // in case no reverse   
      if ( revDiff == 0 ) {
	if ( (char)getc(toPrint) == chg.old ) {
	  fseek(toPrint, chg.offset, SEEK_SET);
	  fwrite(chg.new,1,1,toPrint);
	  if (printMsg == 1) {printf("A change was applied: %s\n",diffLine);}
	}	
      }
      
      // in case reverse was needed
      else{
	if ( (char)getc(toPrint) == chg.new ) {
	  fseek(toPrint, chg.offset, SEEK_SET);
	  fwrite(chg.old,1,1,toPrint);
	  if (printMsg == 1) {printf("A change was applied (reverse): %s\n",diffLine);}
	}	
      }
       
      fclose(toPrint);
      return 0;
}
  
