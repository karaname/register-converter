/* count.c
   Amount different symbols
*/

#include <stdio.h>
#include <ctype.h>

void count(unsigned char *s)
{
  int anum, even, odd;
  int achar, asymb, aspace, aletter;

  anum = even = odd = 0;
  achar = asymb = aspace = aletter = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    if (isprint(s[i])) achar++;

    if (isdigit(s[i])) {
      anum++;
      (s[i] % 2 == 0) ? even++ : odd++;
    } else if (isalpha(s[i])) {
      aletter++;
    } else if (isspace(s[i])) {
      aspace++;
    } else {
      asymb++;
    }
  }

  printf("-------------------------------------------------------");
  printf("\n total chars     - %-5d / letters - %d\n", achar, aletter);
  printf(" special symbols - %-5d / spaces  - %d\n", asymb, aspace);
  printf(" numbers         - %-5d / even    - %-5d / odd - %d\n", anum, even, odd);
}
