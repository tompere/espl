#include <unistd.h>
#include <string.h>
#include <stdio.h>

int
main(int argc, char *argv[ ]) {
    int c;
    int hOptionActive =0;
    int nOptionActive=0;
    int qOptionActive =0;
    char *firstNumberOfDiffStr;
    char *fileOld;
    char *fileNew;
    int placeOfChar = 0;
    int numOfDiff = 0;
    int firstNumberOfDiff =0;
   // extern char *optarg;
    //extern int optind, optopt;
    
    
    //recieving the options
    while ((c = getopt(argc, argv, "hn:q")) != -1) {
        switch(c) {
        case 'h':
	  hOptionActive++;
	  printf("\r\noptions summery:\r\n");
	  printf("\r\n-h  print a summary of options and exit\r\n");
	  printf("\r\n-n NUMBER  print first NUMBER differences and exit\r\n");
	  printf("\r\n-q do not print out the differences, exist with code 0 ");
	  printf("if the files are identical, 1 otherwise\r\n");
	  return 0;
          break;
        case 'n':
	  nOptionActive = nOptionActive + 2;
	  //printf("\r\nn option\r\n");
           firstNumberOfDiffStr = optarg;
	   firstNumberOfDiff = atoi(firstNumberOfDiffStr);
            break;
	case 'q':
	  qOptionActive++;
	  //printf("\r\nq option\r\n");
          break;
        }
    }
    
     
    
    //recieving the files
    int argumentNumOfFileOld = 1 + qOptionActive + nOptionActive + hOptionActive;
    fileOld = argv[optind];
    fileNew = argv[optind+1];

    
    FILE *fpOld;
    fpOld=fopen(fileOld, "r");
    if (fpOld == NULL){
      	 printf("the program cannot open the old file and will exit");
      return 0;
    }
    FILE *fpNew;
    fpNew=fopen(fileNew, "r");    
       if (fpNew == NULL){
	 printf("the program cannot open the new file and will exit");
      return 0;
       }
    
    
    
    //------------------------------------------------------------------------------------------------
	char chOld;
	char chNew;

    while (    (fread(&chOld, sizeof(chOld), 1, fpOld)) && (fread(&chNew, sizeof(chNew), 1, fpNew))){

       
       
       
      if(chOld != chNew){
	if (qOptionActive ==1)
	  return 1;
	
	numOfDiff++;
	if  ((nOptionActive != 0) && (numOfDiff <= firstNumberOfDiff) ) {
	printf("\r\nbyte %d -%x +%x\r\n", placeOfChar, chOld, chNew);
	}
	if(nOptionActive == 0){
	printf("\r\nbyte %d -%x +%x\r\n", placeOfChar, chOld, chNew);

	}
      }
      
      placeOfChar++;
    }
    
    	if ( (qOptionActive ==1) && (numOfDiff == 0) )
	  return 0;
	
	
	
	
	return 0;
    
}





