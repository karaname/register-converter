/* conv.c
   Conversion text to different registers
*/

#include "include.h"
#include "header.h"

void input(char *c)
{
  scanf(" %[^\n]", c);
  if (strlen(c) > BUFFER_SIZE)
    exit(EXIT_FAILURE);
}

void conv_reg(int n)
{
  char c[BUFFER_SIZE];

  if (n == N_COUNT) {
    input(c);
    count(c);
  }

  if (n == N_TITLE) {
    puts("lowercase --> title\n");
    input(c);

    if (c[0] >= 'a' && c[0] <= 'z') c[0] -= 32;

    for (int i = 0; c[i] != '\0'; i++) {
      if (c[i] == ' ' && i++)
        if (c[i] >= 'a' && c[i] <= 'z')
          c[i] -= 32;
    }

    printf("\n%s\n", c);
    count(c);
  }

  if (n == N_REVERSE) {
    puts("text --> reverse\n");
    input(c);

    int s, i, j;
    for (i = 0, j = strlen(c) - 1; i < j; i++, j--)
      s = c[i], c[i] = c[j], c[j] = s;

    printf("\n%s\n", c);
    count(c);
  }

  if (n == N_LOWERCASE) {
    puts("lowercase -> uppercase\n");
    input(c);

    for (int i = 0; c[i] != '\0'; i++) {
      if (c[i] >= 'a' && c[i] <= 'z')
        c[i] -= 32;
    }

    printf("\n%s\n", c);
    count(c);
  }

  if (n == N_UPPERCASE) {
    puts("uppercase -> lowercase\n");
    input(c);

    for (int i = 0; c[i] != '\0'; i++) {
      if (c[i] >= 'A' && c[i] <= 'Z')
        c[i] += 32;
    }

    printf("\n%s\n", c);
    count(c);
  }
}
