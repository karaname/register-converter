/* conv.c
   Conversion text to lowercase / uppercase / title / reverse
*/

#include <stdio.h>

void input(char *value)
{
  scanf("%50[^\n]", value);
}

void lowercase(char *arr)
{
  puts("Enter uppercase words:\n");
  input(arr); int i;

  for (i = 0; arr[i] != '\0'; i++) {
    if (arr[i] >= 65 && arr[i] <= 90)
      arr[i] += 32; // (A - Z) -> a -z
  }

  arr[i] = '\0';
  printf("\n%s\n", arr);
}

void uppercase(char *arr)
{
  puts("Enter lowercase words:\n");
  input(arr); int i;

  for (i = 0; arr[i] != '\0'; i++) {
    if (arr[i] >= 97 && arr[i] <= 122)
      arr[i] -= 32; // (a - z) -> A - Z
  }

  arr[i] = '\0';
  printf("\n%s\n", arr);
}

void title(char *arr)
{
  puts("Enter lowercase sentence:\n");
  input(arr); int i;

  // conversion first symbol
  if (arr[0] >= 97 && arr[0] <= 122) arr[0] -= 32;

  for (i = 0; arr[i] != '\0'; i++) {
    if (arr[i] == ' ' && i++)
      if (arr[i] >= 97 && arr[i] <= 122)
        arr[i] -= 32;
  }

  arr[i] = '\0';
  printf("\n%s\n", arr);
}


void reverse(char *arr)
{
  puts("Enter words:\n");
  input(arr);

  char reverse[50];
  int i, begin, end;

  // i -> length
  for (i = 0; arr[i] != '\0'; i++);
  end = i - 1;

  for (begin = 0; begin < i; ++begin) {
    reverse[begin] = arr[end];
    end--;
  }

  // end of reverse list
  reverse[i] = '\0';
  printf("\n%s\n", reverse);
}
