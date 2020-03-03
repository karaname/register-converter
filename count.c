/* count.c
   Amount different symbols / numbers
*/

#include <stdio.h>

void count(char *arr)
{
  int ai, si, anumber, even, odd;
  int achar, asymb, aspace, aletter;

  char special_symbols[31] = {
    '`',  '~',  '!',  '@',  '#',  '$',  '%',  '^',  '&',
    '*',  '(',  ')',  '_',  '+',  '\'', '\"', '{',  '}',
    ':',  ';',  ',',  '.',  '/',  '\\', '?',  '<',  '>',
    '|',  '=',  '-',  ' '
  };

  anumber = even = odd = 0;
  achar = asymb = aspace = aletter = 0;

  for (ai = 0; arr[ai] != '\0'; ai++ ) {
    // all chars
    if (arr[ai] >= 32 && arr[ai] <= 126) achar++;

    // special symbols
    for (si = 0; special_symbols[si] != '\0'; si++) {
      if (arr[ai] == special_symbols[si]) asymb++;
    }

    // spaces
    if (arr[ai] == ' ') ++aspace;

    // letters A - Z  or  a - z
    if ((arr[ai] >= 65 && arr[ai] <= 90) || (arr[ai] >= 97 && arr[ai] <= 122)) {
      aletter++;
    }

    // numbers
    if (arr[ai] >= 48 && arr[ai] <= 57) {
      anumber++;

      // even / odd
      (arr[ai] % 2 == 0) ? even++ : odd++;
    }
  }

  printf("-------------------------------------------------------");
  printf("\n total chars     - %-5d / letters - %d\n", achar, aletter);
  printf(" special symbols - %-5d / spaces  - %d\n", asymb, aspace);
  printf(" numbers         - %-5d / even    - %-5d / odd - %d\n", anumber, even, odd);
}
