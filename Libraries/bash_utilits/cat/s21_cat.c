#include "s21_cat.h"

int main(int argc, char **argv) {
  Options option = {0};
  parser(argc, argv, &option);

  if (option.b) {
    option.n = 0;
  }

  reader(argv, option);

  return 0;
}

void parser(int argc, char **argv, Options *option) {
  int flag;
  int option_index = 0;
  static struct option long_options[] = {
      {"number", no_argument, 0, 'b'},
      {"show-ends", no_argument, 0, 'e'},
      {"squeeze-blank", no_argument, 0, 's'},
      {"show-tabs", no_argument, 0, 't'},
  };

  while ((flag = getopt_long(argc, argv, "+benstv", long_options,
                             &option_index)) != -1) {
    switch (flag) {
      case 'b':
        option->b = 1;
        break;
      case 'e':
        option->e = 1;
        break;
      case 'n':
        option->n = 1;
        break;
      case 's':
        option->s = 1;
        break;
      case 't':
        option->t = 1;
        break;
      default:
        exit(1);
    }
  }
}

void reader(char **argv, Options option) {
  FILE *file = fopen(argv[optind], "r");
  if (file == NULL) {
    fprintf(stderr, "No such file or directory\n");
    exit(1);
  }

  int current;
  int empty_str = 1;
  int prev_char = '\n';
  int output_line_number = 1;

  while ((current = fgetc(file)) != EOF) {
    if (option.e) {
      if (current == '\n' || current == '$') {
        if (prev_char == '\n' && current == '$') {
        } else {
          putchar('$');
        }
      }
      prev_char = current;
    } else if (option.s) {
      if (current == '\n') {
        if (empty_str) {
          while ((current = fgetc(file)) == '\n') {
          }
          current = fgetc(file);
          if (current != EOF) {
            ungetc(current, file);
            putchar('\n');
          } else {
            if (prev_char == '\n') {
              continue;
            }
          }
        }
      }
    } else if (option.t) {
      if (current == '\t') {
        putchar('^');
        current = 'I';
      }
    } else if (option.b && current != '\n' && empty_str) {
      printf("%6d\t", output_line_number);
      output_line_number++;
    }
    if (option.n && empty_str) {
      printf("%6d\t", output_line_number);
      output_line_number++;
    }
    putchar(current);

    if (current == '\n') {
      if (!option.b && !option.n) {
        empty_str = 1;
      }
    } else {
      empty_str = 0;
    }
  }
  fclose(file);
}
