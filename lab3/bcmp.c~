#include <unistd.h>
#include <string.h>
#include <stdio.h>

int
main(int argc, char *argv[ ]) {
  
   //recieving the options
   int c;
   int firstNDiff = -1; //
   int printBytes = 1; // 0- don;t print, 1- printBytes
   FILE *file1;
   FILE *file2;
   
   while ((c = getopt(argc, argv, "hnq")) != -1) {
     printf("%d",optind);   
     switch(c) {
        case 'h':
	  printf("\r\n=====options summery:======\r\n");
	  printf("-h  print a summary of options and exit\r\n");
	  printf("-n NUMBER  print first NUMBER differences and exit\r\n");
	  printf("-q do not print out the differences, exist with code 0 ");
	  printf("if the files are identical, 1 otherwise\r\n");
	  printf("====================\r\n");
	  return 0;
        case 'n':
	  firstNDiff = atoi(argv[2]);
	  file1 = fopen(argv[3], "r");
	  file2 = fopen(argv[4], "r");
          break;
	case 'q':
	  printBytes = 0;
	  file1 = fopen(argv[2], "r");
	  file2 = fopen(argv[3], "r");
          break;
        default:
	  printf("fff");
	  file1 = fopen(argv[1], "r");
	  file2 = fopen(argv[2], "r");
	  break;
	}
    }
   
    // TODO
    
    
    int countDiff = 0;
    char c1;
    char c2;
    int position = -1;
    
    // read bytes from file (stream) - 4 bytes per iteration, and XOR it with results (accumelator)
    while(fread(&c1,1, 1, file1) && fread(&c2,1, 1, file2)) {
      position++;
      if ((c1 != c2)) {
	if (countDiff == firstNDiff) {break;}
	countDiff++;
	if ( printBytes == 1 ) {
	  printf("byte %d ",position);
	  printf("-%d ",c1);
	  printf("+%d\r\n",c2);
	}
     }
    }
    
    // in case user asked not to print differeneces
    if (printBytes == 0) {
      if (countDiff > 0) printf("1\r\n");
      else printf("0\r\n");
    }
   
    return 0;
}