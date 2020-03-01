/* count.c
   Amount different symbols / numbers
*/

#include <stdio.h>

void count()
{
  char state;
  int anumber, even, odd;
  int achar, asymb, aletter, aword, aline, value;

  anumber = even = odd = 0;
  achar = asymb = aletter = aword = aline = 0;

  #define NUMBER 1
  #define CHAR 0

  printf("Enter something. CTRL + D - EOF\n\n");
  while ((value = getchar()) != EOF) {
    // all chars
    if (value >= 33 && value <= 126) achar++;

    // special symbols
    if (value == ' ' || value == '\n' || value == '\t') asymb++;

    // letters A - Z  or  a - z
    if ((value >= 65 && value <= 90) || (value >= 97 && value <= 122)) {
      state = CHAR;
      if (value != ' ') aletter++;
    }

    // words
    if ((state != NUMBER) && (value == '\n' || value == ' ')) aword++;

    // lines
    if (value == '\n') aline++;

    // numbers
    if (value >= 48 && value <= 57) {
      state = NUMBER;
      anumber++;

      // even / odd
      (value % 2 == 0) ? even++ : odd++;
    }
  }

  printf("\nchars - %-3d / letters - %-3d / special symbols - %d\n", achar, aletter, asymb);
  printf("words - %-3d / lines - %-5d / numbers - %d\n", aword, aline, anumber);
  printf("even numbers - %d / odd numbers - %d\n", even, odd);
}
