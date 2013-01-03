

#include <unistd.h>
#include <string.h>
#include <stdio.h>

FILE* read_file(char* file_name){
      FILE *file;
      file=fopen(file_name, "r");
    if (file == NULL){
      	 printf("the program cannot open the old file and will exit");
      
    }
    return file;
  
}


  void diffLoop(FILE *fpOld, FILE *fpNew){
  	char chOld;
	char chNew;
	int placeOfChar = 0;
    while (    (fread(&chOld, sizeof(chOld), 1, fpOld)) && (fread(&chNew, sizeof(chNew), 1, fpNew))){

       
       
       
      if(chOld != chNew){
	printf("\r\nbyte %d -%x +%x\r\n", placeOfChar, chOld, chNew);
      }
      
      placeOfChar++;
    }
    
  }






int old_main(int argc, char *argv[ ]) {
    char *fileOld;
    char *fileNew;
    
    //recieving the files
    fileOld = argv[1];
    fileNew = argv[2];
    
    FILE *fpOld;
    fpOld = read_file(fileOld);
    
    FILE *fpNew;
    fpNew = read_file(fileNew);
    
    diffLoop(fpOld, fpNew);
    
    	
	return 0;
    
}





