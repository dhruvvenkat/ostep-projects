#include "stdio.h"
#include "unistd.h"

int main(int argc, char *argv[]) {
	FILE *fptr;
	if (argc == 1) {
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		if (access(argv[i], R_OK) != 0) {
			printf("wcat: cannot open file\n");
			return 1;
		}
		fptr = fopen(argv[i], "r");	
		char buf[10000];
		
		while (fgets(buf, 10000, fptr) != NULL) {
			printf("%s", buf);
		};
	
		fclose(fptr);	
	}
	
	return 0;
}
