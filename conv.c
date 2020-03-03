/* conv.c
   Conversion text to title / reverse / lowercase / uppercase
*/

#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

char *input(char *value)
{
  // " %[]" - skip optional space (enter)
  scanf(" %[^\n]", value);

  if (value[0] == '\0')
    usage(EXIT_FAILURE);

  return value;
}

void conv_reg(int n)
{
  char reverse[50];
  char value[50];
  char *arr;
  int i;

  if (n == 2) { // only count
    arr = input(value);
    count(arr);
  }

  if (n == 3) {
    puts("lowercase -> title\n");
    arr = input(value);

    // first symbol
    if (arr[0] >= 97 && arr[0] <= 122) arr[0] -= 32;

    // other
    for (i = 0; arr[i] != '\0'; i++) {
      if (arr[i] == ' ' && i++)
        if (arr[i] >= 97 && arr[i] <= 122)
          arr[i] -= 32;
    }

    printf("\n%s\n", arr);
    count(arr);
  }

  if (n == 4) {
    int i, begin, end;

    puts("symbols -> reverse\n");
    arr = input(value);

    // i -> length
    for (i = 0; arr[i] != '\0'; i++);
    end = i - 1;

    for (begin = 0; begin < i; ++begin) {
      reverse[begin] = arr[end];
      end--;
    }

    reverse[i] = '\0';
    printf("\n%s\n", reverse);
    count(arr);
  }

  if (n == 5) {
    puts("uppercase -> lowercase\n");
    arr = input(value);

    for (i = 0; arr[i] != '\0'; i++) {
      if (arr[i] >= 65 && arr[i] <= 90)
        arr[i] += 32; // (A - Z) -> a -z
    }

    printf("\n%s\n", arr);
    count(arr);
  }

  if (n == 6) {
    puts("lowercase -> uppercase\n");
    arr = input(value);

    for (i = 0; arr[i] != '\0'; i++) {
      if (arr[i] >= 97 && arr[i] <= 122)
        arr[i] -= 32; // (a - z) -> A - Z
    }

    printf("\n%s\n", arr);
    count(arr);
  }
}
