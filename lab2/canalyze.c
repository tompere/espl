#include <stdio.h>
#include <stdlib.h>
#include "fgetname.h"
#include "namelist.h"
#include <string.h>

// a comparison funtion to compare two names in the names array
int struct_cmp_by_name(const void *a, const void *b);

int main(int argc, char **argv) {
  char *keywords[33] ={
			"auto", "break", "case", "char", "const", "continue", "default", "do",
			"double","else","enum","extern","float","for","goto","if","int","long",
			"register","return","short","signed","sizeof","static","struct","switch",
			"typedef","union","unsigned","void","volatile","while",NULL
  };
  
  //make a new name list
  namelist nl = make_namelist();
  int is_key_word,i,j;
  // for each file print all the words
  for (i =1; i< argc; i++){
    FILE *stream = fopen(argv[i], "r");	
    char name[NAMELEN];
    if(!stream) {
      fprintf(stderr, "run the test in the source directory\n");
      return 1; 
    }
    //for each name in the file, add the name to the namelist
    while(fgetname(name, NAMELEN, stream)){
      is_key_word= 0;
      for(j=0; j<32; j++){
	if ( strcmp(keywords[j],name) ==0){
	  add_name(nl, name);
	}
      }
    }
      fclose(stream);
  } // end of dealing with on argv
  int nl_names_size= (sizeof(nl->names)) / sizeof (char*);
  qsort(nl->names, nl->size ,sizeof(struct namestat), struct_cmp_by_name);
  for(i = 0; i<nl->size; i++) {
    if ((nl->names[i].count) ==1) { 
      printf("%s ", nl->names[i].name);
      printf("%d\n", nl->names[i].count);
    }
  }
  return 0; 

}

int struct_cmp_by_name(const void *a, const void *b) { 
  return strcmp(((struct namestat*)a)->name,((struct namestat*)b)->name);
}
