#ifndef CAT_H
#define CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
} Options;

void parser(int argc, char **argv, Options *oprion);
void reader(char **argv, Options oprion);

#endif
