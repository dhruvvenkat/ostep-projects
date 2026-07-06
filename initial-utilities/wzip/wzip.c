#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("wzip: file1 [file2 ...]\n");
		return 1;
	}

	int previous = EOF;
	int count = 0;

	for (int i = 1; i < argc; i++) {
		FILE *file = fopen(argv[i], "r");
		if (file == NULL) {
			printf("wzip: cannot open file\n");
			return 1;
		}

		int current;
		while ((current = fgetc(file)) != EOF) {
			if (current == previous) {
				count++;
			} else {
				if (previous != EOF) {
					fwrite(&count, sizeof(count), 1, stdout);
					fputc(previous, stdout);
				}
				previous = current;
				count = 1;
			}
		}

		fclose(file);
	}

	if (previous != EOF) {
		fwrite(&count, sizeof(count), 1, stdout);
		fputc(previous, stdout);
	}

	return 0;
}
