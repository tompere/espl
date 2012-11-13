#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "diff.h"

int main(int argc, char *argv[ ]) {
  
   //recieving all arguments (options and/or input files)
   int c;
   int printMsg = 0; //option m : 0- don;t print, 1- printBytes
   int revDiff = 0; // option r: 0- regular, 2- apply difference by reverse
   FILE *toPrint; //input file: original file to fix
   FILE *difference; //input file: differences file, as recieved by bcmp.c
   
   while ((c = getopt(argc, argv, "hrm")) != -1) {  
     switch(c) {
        case 'h':
	  printf("\r\n=====options summery:======\r\n");
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
    
    // parsing input file into tokens (newLine delimeter)
   char diffLine[300];
   
   difference = fopen(argv[optind+1], "r");
   struct diff theDiff;
	 
   while(fgets(diffLine,sizeof(diffLine),difference) != NULL)
   {      
     // get difference (per line) 

      parsediff(diffLine, &theDiff);
      
      // open input file again
      toPrint = fopen(argv[optind], "rb+");
      
      // read bytes from file (stream) - 4 bytes per iteration, and XOR it with results (accumelator)
      fseek(toPrint,theDiff.offset, SEEK_SET);
      
      // in case no reverse
      
      if ( revDiff == 0 ) {
	if ( (char)getc(toPrint) == theDiff.old ) {
	  fseek(toPrint,theDiff.offset,SEEK_SET);
	  fwrite(&theDiff.new,1,1,toPrint);
	  if (printMsg == 1) {printf("A change was applied: %s\n",diffLine);}
	}	
      }
      
      // in case reverse was needed
      
      else{
	if ( (char)getc(toPrint) == theDiff.new ) {
	  fseek(toPrint,theDiff.offset,SEEK_SET);
	  fwrite(&theDiff.old,1,1,toPrint);
	  if (printMsg == 1) {printf("A change was applied (reverse): %s\n",diffLine);}
	}	
      }
       
      fclose(toPrint);

    }
    
     fclose(difference);
     return 0;
      
   }