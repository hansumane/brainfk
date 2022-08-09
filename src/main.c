#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define ARRCAP 30000

int
main (int argc, char **argv)
{
  int debug_flag = 0;
  int no_newline_flag = 0;
  char *filename, *cmd = NULL;
  char arr[ARRCAP] = { };

  if (argc < 2)
    {
      fputs ("Not enough arguments!\n"
             "Please provide the file name!\n", stderr);
      exit (1);
    }
  else
    for (int i = 0; i < argc; ++i)
      {
        if (!strcmp (argv[i], "-d") || !strcmp (argv[i], "--debug"))
          debug_flag = 1;
        else if (!strcmp (argv[i], "-n") || !strcmp (argv[i], "--no-newline"))
          no_newline_flag = 1;
        else if (argv[i][0] != '-')
          filename = argv[i];
      }

  rdcmds (&cmd, filename);
  go (cmd, arr);
  if (lastput != '\n' && !no_newline_flag)
    putchar ('\n');

  if (debug_flag)
    for (size_t i = 0; i < 4; ++i)
      {
        for (size_t j = 16 * i; j < 16 * (i + 1); ++j)
          printf ("%3hhu, ", arr[j]);
        putchar ('\n');
      }

  return 0;
}
