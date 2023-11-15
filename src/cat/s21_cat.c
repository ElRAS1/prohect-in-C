#include "parser.h"

int main(int argc, char **argv) {
  if (argc >= 2) {
    init_options();
    pars(argc, argv);
    print_file(argc, argv);
  } else {
    printf("Please enter a filename\n");
  }
  return 0;
}

int pars(int argc, char *argv[]) {
  int c;
  while ((c = getopt_long(argc, argv, "beEnstTv", flags, 0)) != -1) {
    switch (c) {
      case 'b':
        flag.b = 1;
        break;
      case 'e':
        flag.e = 1;
        flag.v = 1;
        break;
      case 'n':
        flag.n = 1;
        break;
      case 's':
        flag.s = 1;
        break;
      case 'v':
        flag.v = 1;
        break;
      case 't':
        flag.t = 1;
        flag.v = 1;
        break;
      case 'T':
        flag.t = 1;
        break;
      case 'E':
        flag.e = 1;
        break;
    }
  }
  return 0;
}

void print_file(int argc, char *argv[]) {
  int line;
  int new_line;
  int end_line;
  int x;

  for (int i = optind; i < argc; i++) {
    line = 1;
    new_line = 1;
    end_line = 0;
    FILE *f = fopen(argv[i], "r");

    if (f != NULL) {
      while ((x = fgetc(f)) != EOF) {
        if (flag.b && new_line && x != '\n') {
          printf("%6d\t", line);
          line++;
          new_line = 0;
        }

        if (flag.n && new_line) {
          printf("%6d\t", line);
          line++;
          new_line = 0;
        }

        if (flag.e && x == '\n') {
          printf("$");
        }
        if (flag.s) {
          if (x == '\n') {
            ++end_line;
            if (end_line > 2) {
              continue;
            }
          } else {
            end_line = 0;
          }
        }
        if (flag.t && x == '\t') {
          printf("^");
          x = 'I';
        }
        if (flag.v && x != '\n' && x != '\t') {
          if (x >= 0 && x <= 31) {
            printf("^");
            x += 64;
          } else if (x == 127) {
            printf("^");
            x -= 64;
          }
        }

        if (x == '\n') new_line = 1;
        printf("%c", x);
      }
    } else {
      printf("s21_cat: %s: No such file or directory\n", argv[i]);
    }
    fclose(f);
  }
}
