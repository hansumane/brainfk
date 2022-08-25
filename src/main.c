#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define ARRCAP 30000

int
main(int argc, char **argv)
{
  int debug_flag = 0;
  int no_newline_flag = 0;
  unsigned debug_amount = 1;

  char arr[ARRCAP] = { };
  char *filename, *cmd = NULL;
  struct ret_t done = { NULL, NULL };

  if (argc < 2)
    {
      fputs("Not enough arguments!\n"
            "Please provide the file name!\n", stderr);
      exit(1);
    }
  else
    for (int i = 1; i < argc; ++i)
      {
        if (argv[i][0] != '-')
          filename = argv[i];
        else if (strlen(argv[i]) == 2)
          switch (argv[i][1])
            {
            case 'd':
              debug_flag = 1;
              break;
            case 'n':
              no_newline_flag = 1;
              break;
            }
        else if (strlen(argv[i]) >= 3)
          if (argv[i][0] == '-' && argv[i][1] == 'd' && argv[i][2] != '\0')
            {
              debug_flag = 1;
              debug_amount = (unsigned) atoi(&argv[i][2]);
            }
      }

  rdcmds(&cmd, filename);
  done = go(cmd, arr);
  if (lastput != '\n' && !no_newline_flag)
    putchar('\n');

  if (debug_flag)
    {
      for (size_t i = 0; i < debug_amount; ++i)
        {
          for (size_t j = 16 * i; j < 16 * (i + 1); ++j)
            printf("%3hhu, ", arr[j]);
          putchar('\n');
        }
      printf("/final pos: [%zu]/\n", done.arr - arr);
    }

  return 0;
}
