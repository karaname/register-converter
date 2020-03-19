/* count.c
   Amount different symbols / numbers
*/

#include <stdio.h>

void count(char *arr)
{
  int i, anumber, even, odd;
  int achar, asymb, aspace, aletter;

  anumber = even = odd = 0;
  achar = asymb = aspace = aletter = 0;

  for (i = 0; arr[i] != '\0'; i++ ) {
    // all chars
    if (arr[i] >= 32 && arr[i] <= 126) achar++;

    // other
    if (arr[i] >= 48 && arr[i] <= 57) {
      anumber++;
      // even / odd
      (arr[i] % 2 == 0) ? even++ : odd++;
    } else if ((arr[i] >= 65 && arr[i] <= 90)|| (arr[i] >= 97 && arr[i] <= 122)) {
      // letters
      aletter++;
    } else if (arr[i] == ' ') {
      // spaces
      aspace++;
    } else {
      // special symbols
      asymb++;
    }
  }

  printf("-------------------------------------------------------");
  printf("\n total chars     - %-5d / letters - %d\n", achar, aletter);
  printf(" special symbols - %-5d / spaces  - %d\n", asymb, aspace);
  printf(" numbers         - %-5d / even    - %-5d / odd - %d\n", anumber, even, odd);
}
