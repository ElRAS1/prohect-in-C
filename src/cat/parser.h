#include <getopt.h>
#include <stdio.h>

void init_options();
int pars(int argc, char *argv[]);
void print_file(int argc, char *argv[]);

struct flag {
  int b;
  int e;
  int n;
  int s;
  int T;
  int t;
  int v;
} flag;

struct option flags[] = {
    {"number-nonblank", no_argument, 0, 'b'},
    {"E", no_argument, 0, 'E'},
    {"e", no_argument, 0, 'e'},
    {"number", no_argument, 0, 'n'},
    {"squeeze-blank", no_argument, 0, 's'},
    {"T", no_argument, 0, 'T'},
    {"t", no_argument, 0, 't'},
    {"v", no_argument, 0, 'v'},
};

void init_options() {
  flag.b = 0;
  flag.e = 0;
  flag.n = 0;
  flag.s = 0;
  flag.T = 0;
  flag.t = 0;
  flag.v = 0;
}
