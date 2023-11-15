#include "grep_pars.h"

int main(int argc, char **argv) {
  init_options();
  if (pars(argc, argv) == 0) {
    char *pattern;
    if (!flag.e) {
      pattern = argv[optind];
      optind++;
    }
    if (flag.f) {
      optind--;
    }
    int fl_count = argc - optind;
    while (optind < argc) {
      if (flag.e || flag.f) {
        grep(flag.patterns, fl_count, argc, argv);
      } else {
        grep(pattern, fl_count, argc, argv);
      }
      optind++;
    }
    return 0;
  }
}

int pars(int argc, char *argv[]) {
  int c;
  while ((c = getopt_long(argc, argv, "e:ivclnhsof:", flags, 0)) != -1) {
    switch (c) {
      case 'e':
        flag.e = 1;
        strcat(flag.patterns, optarg);
        strcat(flag.patterns, "|");
        break;
      case 'i':
        flag.i = 1;
        break;
      case 'v':
        flag.v = 1;
        break;
      case 'c':
        flag.c = 1;
        break;
      case 'l':
        flag.l = 1;
        break;
      case 'n':
        flag.n = 1;
        break;
      case 'h':
        flag.h = 1;
        break;
      case 's':
        flag.s = 1;
        break;
      case 'o':
        flag.o = 1;
        break;
      case 'f':
        flag.f = 1;
        strcat(flag.pattern_f, optarg);
        flag_f();
        break;
    }
  }
  if (flag.e || flag.f) {
    flag.patterns[strlen(flag.patterns) - 1] = '\0';
  }
  if (!flag.l && !flag.c && !flag.e && !flag.n && !flag.i && !flag.v &&
      !flag.f && !flag.h && !flag.o && !flag.s) {
    flag.fl = REG_EXTENDED;
    flag.ch_emptyOption = 1;
  }
  return 0;
}

void grep(char *pattern, int fl_count, int argc, char **argv) {
  regex_t pregs;
  char *filename = argv[optind];
  FILE *f = fopen(filename, "r");

  flag.fl_fe = 1;
  if ((!flag.s && f == NULL) &&
      (flag.l || flag.c || flag.e || flag.n || flag.i || flag.v || flag.f ||
       flag.h || flag.o || flag.fl)) {
    printf("%s: %s\n", filename, "No such file or directory");

  } else if (f != NULL) {
    if (flag.i) {
      flag.fl |= REG_ICASE;
    }
    if (regcomp(&pregs, pattern, flag.fl) != 1) {
      grepfile(f, &pregs, argc, filename, fl_count, pattern);
    }
  fclose(f);
  }
}

void grepfile(FILE *f, regex_t *preg, int argc, char *filename, int fl_count,
              char *pattern) {
  int status, count = 0, ln = 1, x = 0;
  char *line = NULL;
  size_t length = 0;
  regmatch_t match;
  while (getline(&line, &length, f) > 0) {
    status = regexec(preg, line, 1, &match, 0);
    if (flag.i && !flag.n && !flag.v && status == 0) {
      if (fl_count > 1) {
        printf("%s:%s", filename, line);
      } else {
        printf("%s", line);
      }
    }
    if (flag.i && flag.n && status == 0) {
      if (fl_count > 1) {
        printf("%s:%d:%s", filename, ln, line);
      } else {
        printf("%d:%s", ln, line);
      }
    }
    if (flag.i && flag.v && status != 0) {
      if (fl_count > 1) {
        printf("%s:%s", filename, line);
      } else {
        printf("%s", line);
      }
    }
    if (!flag.i && flag.v && status != 0) {
      if (fl_count > 1) {
        printf("%s:%s", filename, line);
      } else {
        printf("%s", line);
      }
    }
    if (flag.c && status == 0) {
      count++;
    }
    if (!flag.i && flag.n && status == 0) {
      if (fl_count > 1) {
        printf("%s:%d:%s", filename, ln, line);
      } else {
        printf("%d:%s", ln, line);
      }
    }
    if (flag.h && status == 0) {
      printf("%s", line);
    }
    if (flag.l && status == 0 && x == 0) {
      x = 1;
    }

    if ((flag.s || flag.ch_emptyOption || flag.e || flag.f) && status == 0) {
      if (fl_count > 1) {
        printf("%s:%s", filename, line);
      } else {
        printf("%s", line);
      }
    }
    if (flag.o && status == 0) {
      if (fl_count > 1) {
        printf("%s:%s\n", filename, pattern);
      } else {
        printf("%s\n", pattern);
      }
    }

    ln++;
  }

  if (flag.c) {
    if (argc > 4) {
      printf("%s:%d", filename, count);
    } else {
      printf("%d", count);
    }
  }
  if (flag.v || flag.c) {
    printf("\n");
  }
  if (flag.l && x == 1) {
    printf("%s\n", filename);
  }
  free(line);
  regfree(preg);
}

void flag_f() {
  FILE *ff = fopen(flag.pattern_f, "r");
  if (ff != NULL) {
    while (!feof(ff)) {
      if (fgets(flag.file_pattern, 1000, ff) != NULL) {
        if (flag.file_pattern[strlen(flag.file_pattern) - 1] == '\n' &&
            strlen(flag.file_pattern) - 1 != 0)
          flag.file_pattern[strlen(flag.file_pattern) - 1] = '\0';
        strcat(flag.patterns, flag.file_pattern);
        strcat(flag.patterns, "|");
      }
    }
    fclose(ff);
  }
}
