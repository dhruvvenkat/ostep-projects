#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    int count = 0;

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("wunzip: cannot open file\n");
            return 1;
        }

        char current;
        while (fread(&count, sizeof(int), 1, file) == 1) {
            fread(&current, sizeof(char), 1, file);

            for (int i = 0; i < count; i++) {
                putchar(current);
            }
        }
    }
}
