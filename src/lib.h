typedef struct ret_t { char *cmd, *arr; } ret_t;

void rdcmds(char **to, const char *filename)
{
    char buffer;
    FILE *input;
    size_t i = 0, cmdsiz = 0;
    size_t bopen = 0, bclose = 0;

    if (!(input = fopen(filename, "r"))) {
        fprintf(stderr, "No such file: %s\n", filename);
        exit(1);
    }

    while (fread(&buffer, sizeof(char), 1, input))
        switch (buffer) {
            case '[':
                ++bopen;
                --bclose;
            case ']':
                ++bclose;
            case '>':
            case '<':
            case '+':
            case '-':
            case '.':
            case ',':
                ++cmdsiz;
        }

    if (bopen != bclose) {
        fprintf(stderr, "Syntax error! the amount of open brackets (%zu)\n"
                "is not the same as the amount of closing brackets (%zu)\n",
                bopen, bclose);
        exit(2);
    }

    fclose(input);
    input = fopen(filename, "r");

    free(*to);
    *to = (char *) calloc(cmdsiz + 1, sizeof(char));

    while (fread(&buffer, sizeof(char), 1, input))
        switch (buffer)
            case '>':
            case '<':
            case '+':
            case '-':
            case '.':
            case ',':
            case '[':
            case ']':
                (*to)[i++] = buffer;
}

ret_t skip(char *cmd, char *arr)
{
    ret_t tmp;
    size_t obmnt = 0;

    do {
        while (*cmd++ != ']')
            if (*cmd == '[')
                ++obmnt;
    } while (obmnt--);

    tmp.cmd = --cmd;
    tmp.arr = arr;
    return tmp;
}

ret_t go(char *cmd, char *arr)
{
    ret_t tmp;
    while (*cmd != '\0' && *cmd != ']') {
        switch (*cmd) {
            case '>': ++arr;
                      break;
            case '<': --arr;
                      break;
            case '+': ++*arr;
                      break;
            case '-': --*arr;
                      break;
            case '.': putchar(*arr);
                      fflush(stdout);
                      break;
            case ',': *arr = getchar();
                      break;
            case '[': if (*arr) {
                          while (*arr) {
                              tmp = go(cmd + 1, arr);
                              arr = tmp.arr;
                          }
                          cmd = tmp.cmd;
                      } else {
                          tmp = skip(cmd, arr);
                          cmd = tmp.cmd;
                          arr = tmp.arr;
                      }
        } ++cmd;
    }
    tmp.cmd = cmd;
    tmp.arr = arr;
    return tmp;
}
