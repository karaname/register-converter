/* count.c
   Amount different symbols
*/

#include <stdio.h>

void count(char *s)
{
  int anum, even, odd;
  int achar, asymb, aspace, aletter;

  anum = even = odd = 0;
  achar = asymb = aspace = aletter = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    // all chars
    if (s[i] >= 32 && s[i] <= 126) achar++;

    // others
    if (s[i] >= '0' && s[i] <= '9') {
      anum++; // numbers
      // even - odd
      (s[i] % 2 == 0) ? even++ : odd++;
    } else if ((s[i] >= 'A' && s[i] <= 'Z') ||
      (s[i] >= 'a' && s[i] <= 'z')) {
      // letters
      aletter++;
    } else if (s[i] == ' ') {
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
  printf(" numbers         - %-5d / even    - %-5d / odd - %d\n", anum, even, odd);
}
