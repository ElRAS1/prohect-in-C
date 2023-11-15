#define _GNU_SOURCE
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffer 4096

void init_options();
int pars(int argc, char *argv[]);
void grepfile(FILE *f, regex_t *preg, int argc, char *filename, int fl_count,
              char *pattern);
void grep(char *pattern, int fl_count, int argc, char **argv);
void flag_f();

struct flagss {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;
  int f;
  char patterns[buffer];
  char pattern_f[buffer];
  char file_pattern[buffer];
  int fl_fe;
  int fl;
  int ch_emptyOption;
} flag;

struct option flags[] = {
    {"ee", no_argument, 0, 'e'}, {"ii", no_argument, 0, 'i'},
    {"vv", no_argument, 0, 'v'}, {"cc", no_argument, 0, 'c'},
    {"ll", no_argument, 0, 'l'}, {"nn", no_argument, 0, 'n'},
    {"hh", no_argument, 0, 'h'}, {"ss", no_argument, 0, 's'},
    {"oo", no_argument, 0, 'o'}, {"ff", no_argument, 0, 'f'}};

void init_options() {
  flag.e = 0;
  flag.i = 0;
  flag.v = 0;
  flag.c = 0;
  flag.l = 0;
  flag.n = 0;
  flag.h = 0;
  flag.s = 0;
  flag.o = 0;
  flag.f = 0;
  flag.fl_fe = 0;
  flag.fl = REG_EXTENDED;
  flag.ch_emptyOption = 0;
}
