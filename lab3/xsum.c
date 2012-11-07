#include <unistd.h>
#include <string.h>
#include <stdio.h>

int
main(int argc, char *argv[ ]) {
    int c;
    int hflg;
    char *xfile;
    extern char *optarg;
    //extern int optind, optopt;
    
    while ((c = getopt(argc, argv, "hx:")) != -1) {
        switch(c) {
        case 'h':
	printf("\r\nhelp!\r\n");
            break;
        case 'x':
	  printf("\r\nx option\r\n");
           xfile = optarg;
	   printf("\r\n%s\r\n", xfile);
            break;

        }
    }
    
    char *test = "BA";
    printf("value: %d%d\r\n",*test);
    printf("converted value: %d%d\r\n",*test-55);
}







   /** 
    

    for ( ; optind < argc; optind++) {
        if (access(argv[optind], R_OK)) {
    . . .
}

T
#include <unistd.h>
#include <string.h>
...
char *Options = "hdbtl";
...
int dbtype, i;
char c;
char *st;
...
dbtype = 0;
while ((c = getopt(argc, argv, Options)) != -1) {
    if ((st = strchr(Options, c)) != NULL) {
        dbtype = st - Options;
        break;
    }
}
**/
