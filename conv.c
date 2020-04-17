/* conv.c
   Conversion text to different registers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

void input(unsigned char *c)
{
  scanf(" %[^\n]", c);

  if (c[0] == '\0') {
    exit(EXIT_SUCCESS);
  }

  for (int i = 0; c[i] != '\0'; i++) {
    if (isprint(c[i]) == 0) {
      usage(EXIT_FAILURE);
    }
  }

  if (strlen(c) > BUFFER_SIZE) {
    exit(EXIT_FAILURE);
  }
}

void conv_reg(int n)
{
  unsigned char c[BUFFER_SIZE];
  input(c);

  if (n == N_TITLE) {
    if (islower(c[0])) *(c) = toupper(c[0]);

    for (int i = 0; c[i] != '\0'; i++) {
      if (isspace(c[i]) && i++) {
        if (islower(c[i])) {
          *(c + i) = toupper(c[i]);
        }
      }
    }

    printf("\n%s\n", c);
  }

  if (n == N_REVERSE) {
    int s, i, j;

    for (i = 0, j = strlen(c) - 1; i < j; i++, j--) {
      s = c[i], c[i] = c[j], c[j] = s;
    }

    printf("\n%s\n", c);
  }

  if (n == N_LOWERCASE) {
    for (int i = 0; c[i] != '\0'; i++) {
      if (isupper(c[i])) *(c + i) = tolower(c[i]);
    }

    printf("\n%s\n", c);
  }

  if (n == N_UPPERCASE) {
    for (int i = 0; c[i] != '\0'; i++) {
      if (islower(c[i])) *(c + i) = toupper(c[i]);
    }

    printf("\n%s\n", c);
  }

  count(c);
}
