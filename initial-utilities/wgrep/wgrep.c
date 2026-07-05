#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *searchTerm = argv[1];
	FILE *fptr;

	if (argc == 1) {
		printf("wgrep: searchterm [file ...]\n");
		return 1;
	}

	// TODO: create a flow for grepping from standard input
	//printf("search term: %s\n", searchTerm);

	// iterate thru each file and look for the search term
	for (int i = 2; i < argc; i++) {
		if (access(argv[i], R_OK) != 0) {
			//continue; // if the file doesn't work or doesn't exist, skip it
			printf("wgrep: cannot open file\n");
			return 1;
		}

		fptr = fopen(argv[i], "r");
		char line[256];
		while (fgets(line, sizeof(line), fptr)) {
			//printf("%s", line);
			if (strstr(line, searchTerm)) {
				printf("%s", line);
			}
			//int found = sscanf(line, )
		}
	}

	
	
}
