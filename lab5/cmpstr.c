#include <stdlib.h>
#include <stdio.h>

int cmpstr(char *str1, char *str2) {
  
  int i = 0;
  //read the stings one char at a time untill there is a differense
  while (1){
    if ( str1[i] == 0 ) break;
    if ( str1[i] != str2[i] ) break;
    i++;
  }
  
  
  if (str1[i] < str2[i]) return 2;
  if (str1[i] > str2[i]) return 1;
  else return 0;
  
}
