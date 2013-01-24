#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int countLines(FILE* fp) {
  
  int c=0;
  char ch='\0';
  
  while(ch!=EOF) {
	ch=fgetc(fp);
	if(ch=='\n')  c++;
  }
  
  return c;
}

int main(int argc, char** argv){
  int lineNum = 1;
  char line [128];
  //printf("%s",argv[1]);
  
  // read the file into fp object
  FILE *fp = fopen(argv[1],"r");
  if (fp == 0 ){
   printf("THE FILE IS INVALID\n");
   return 0;
  }
  
  // get number of lines in the file
  int numLines = countLines(fp);
  printf("there are %d lines in %s", numLines, argv[1]);

 
  // get a random number between 1 and numoflines
  srand(time(NULL));
  int randNum = (rand() % numLines) + 1;
  printf("\nthe rand is %d\n", randNum);
  // get the line by its number
 
  fclose(fp);
  fp = fopen(argv[1],"r");
  
  char ch =fgetc(fp);
   printf("%d: ", randNum);
  while(ch!=EOF) {
    ch=fgetc(fp);	
    if(ch=='\n'){
      lineNum++;
    }
    
    if (lineNum == randNum){
      printf("%c", ch);
    }
     if (lineNum >randNum){
      break;
    }
  }
  printf("\n");
  fclose(fp); 
  return 0;  
  
}


