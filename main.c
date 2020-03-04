/* rcnv - text conversion and counting
   Project for learning C programming
   Rekhov Kirill / 29 - February 2020
*/

#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include "headers.h"

#define N_HELP 1
#define N_COUNT 2
#define N_TITLE 3
#define N_REVERSE 4
#define N_LOWERCASE 5
#define N_UPPERCASE 6
#define PROGRAM_NAME "rcnv"

void usage(int status)
{
  if (status != EXIT_SUCCESS) {
    fprintf(stderr, "Try '%s --help' for more information\n", PROGRAM_NAME);
  } else {
    printf("Usage: %s [OPTION]\n", PROGRAM_NAME);
    fputs("\
Text conversion and counting\n\
\n\
  -c, --count       count the number of different symbols\n\
  -l, --lowercase   accept uppercase and convert in lowercase\n\
  -u, --uppercase   accept lowercase and convert in uppercase\n\
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

  /*
  char *program_name;
  program_name = argv[0];
  */

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
      case 'h': cell = N_HELP; break;
      case 'c': cell = N_COUNT; break;
      case 't': cell = N_TITLE; break;
      case 'r': cell = N_REVERSE; break;
      case 'l': cell = N_LOWERCASE; break;
      case 'u': cell = N_UPPERCASE; break;

      default:
        usage(EXIT_FAILURE);
    }
  }

  if (cell == N_HELP) usage(EXIT_SUCCESS);
  if (cell & (N_COUNT | N_TITLE | N_REVERSE | N_LOWERCASE | N_UPPERCASE))
      conv_reg(cell);

  return 0;
}
