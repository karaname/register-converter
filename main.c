/* rcnv - text conversion and counting
   Project for learning C programming
   Rekhov Kirill / 29 - February 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "header.h"
#define PROGRAM_NAME "rcnv"

void usage(int status)
{
  if (status != EXIT_SUCCESS) {
    fprintf(stderr, "Try '%s --help' for more information\n", PROGRAM_NAME);
  } else {
    printf("Usage: %s [OPTION]\n", PROGRAM_NAME);
    fputs("\
Text ASCII conversion and counting\n\
\n\
  -c, --count       count the number of different symbols\n\
  -l, --lowercase   accept uppercase and convert to lowercase\n\
  -u, --uppercase   accept lowercase and convert to uppercase\n\
  -r, --reverse     reverse text conversion\n\
  -t, --title       title case conversion\n\
\n\
", stdout);
  }

  exit(status);
}

int main(int argc, char *argv[])
{
  int opt, cell;

  struct option long_options[] = {
    { "help",       no_argument,  NULL,  'h' },
    { "count",      no_argument,  NULL,  'c' },
    { "title",      no_argument,  NULL,  't' },
    { "reverse",    no_argument,  NULL,  'r' },
    { "lowercase",  no_argument,  NULL,  'l' },
    { "uppercase",  no_argument,  NULL,  'u' },
    { NULL, 0, NULL, 0 }
  };

  while((opt = getopt_long(argc, argv, "hctrlu", long_options, NULL)) != -1) {
    switch(opt) {
      case 'h': usage(EXIT_SUCCESS); break;
      case 'c': conv_reg(N_COUNT); break;
      case 't': conv_reg(N_TITLE); break;
      case 'r': conv_reg(N_REVERSE); break;
      case 'l': conv_reg(N_LOWERCASE); break;
      case 'u': conv_reg(N_UPPERCASE); break;

      default:
        usage(EXIT_FAILURE);
    }
  }

  return 0;
}
