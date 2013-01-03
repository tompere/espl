#include <unistd.h>
#include <string.h>
#include <stdio.h>

//--------------------------------------------------------------------

// a read file function
  *FILE readFile(char *file_name){
    FILE *file;
    file=fopen(file_name, "r");
    if (file == NULL){
      	 printf("the program cannot open the file and will exit");
      return 0;
    }
    return *file;
}


//--------------------------------------------------------------------

void diff_loop(FILE *fpOld, FILE *fpNew){
    char chOld;
    char chNew;   
    int placeOfChar = 0;
  
  while (    (fread(&chOld, sizeof(chOld), 1, fpOld)) && (fread(&chNew, sizeof(chNew), 1, fpNew))){
      
      // if there is a difference
      if(chOld != chNew){
	printf("\r\nbyte %d -%x +%x\r\n", placeOfChar, chOld, chNew);
	} 
	
      placeOfChar++;
      
    } //end of loop
}

//--------------------------------------------------------------------


//--------------------------------------------------------------------


//--------------------------------------------------------------------

int
old_main(int argc, char *argv[ ]) {
    char *fileOld;
    char *fileNew;

    //recieving the files
    fileOld = argv[2];
    fileNew = argv[3];  
    
    //open the files    
    FILE *fpOld = readFile(fileOld);
    FILE *fpnew = readFile(fileNew);
  
    //do the while loop
    diff_loop(fpOld, fpNew);
	
    //exit the program	
    return 0; 

    
}







