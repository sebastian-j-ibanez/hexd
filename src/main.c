#include <ctype.h>
#include <stdio.h>

#define MAX_LINE 16

void print_help(void) {
    printf("hexd is a binary hexdump util\n\n");
    printf("Usage: hexd [binary file]\n");
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        print_help();
        return 0;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        return -1;
    }

    long offset = 0;
    long size = 0;
    char line[MAX_LINE];
    while((size = fread(line, sizeof(char), MAX_LINE, file)) > 0) {
        printf("%08lx:\t", offset);
        offset += MAX_LINE;
        for (int i = 0; i < MAX_LINE; i++) {
            printf("\033[97m%02x\033[0m ", (unsigned char)line[i]);
        }

        printf("\t");
        for (int i = 0; i < size; i++) {
            if (isprint((unsigned char)line[i])) {
                printf("\033[32m%c\033[0m", (unsigned char)line[i]);
            } else {
                printf("\033[31m%c\033[0m", '.');
            }
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
