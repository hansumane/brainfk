#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define ARRCAP 30000
#define RELEASE

int main(int argc, char **argv)
{
    char *filename, *cmd = NULL;
    char arr[ARRCAP] = {};

    if (argc < 2) {
        fputs("Not enough arguments!\n"
              "Please provide the file name!\n",
              stderr);
        exit(1);
    } else {
        filename = argv[1];
    }

    rdcmds(&cmd, filename);
    go(cmd, arr);
    putchar('\n');

#if !defined(RELEASE)
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 16; ++j)
            printf("%3hhu, ", arr[i]);
        putchar('\n');
    }
#endif /* RELEASE */

    return 0;
}
