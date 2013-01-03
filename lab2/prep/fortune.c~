#include <stdio.h>
#include <string.h>

int main() {
  
  //printf("%s",argv[1]);
  
  // read the file into fp object
  char filename[128];
  FILE *fp = fopen("~/quotes.txt","r");
  
  // get number of lines in the file
  int numLines = countLines(fp);

  /**
  // get a random number between 1 and numoflines
  int randNum = rand() % numLines + 1;
  
  // get the line by its number
  int count = 1;
  char ch='\0';
  char ans;
  while(ch!=EOF) {
	ch=fgetc(fp);
	if(ch=='\n')  count++;
	if (count = randNum) ans = ans + ch;
  }
  
  // printf(randNum + ": " + ans);
  **/
  
  return 0;  
  
}

int countLines(FILE* fp) {
  
  int c=0;
  char ch='\0';
  
  while(ch!=EOF) {
	ch=fgetc(fp);
	if(ch=='\n')  c++;
  }
  return c;
}
