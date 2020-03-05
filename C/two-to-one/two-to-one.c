#include <stdio.h>
#include <stdlib.h>

void aprint(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    putchar(arr[i] + '0');
  putchar('\n');
}

void sprint(char *s)
{
  while (*s != '\0')
    putchar(*s++);
}

char *longest(char *s1, char *s2)
{
  int i, j, alphabet[26];
  for (i = 0; i < 26; i++)
    alphabet[i] = 0;

  for (; *s1 != '\0'; s1++)
    alphabet[*s1 - 'a'] = 1;

  for (; *s2 != '\0'; s2++)
    alphabet[*s2 - 'a'] = 1;

  char *res = (char *)calloc(27, sizeof(char));
  for (i = 0, j = 0; i < 26; i++)
    if (alphabet[i] == 1)
      res[j++] = i + 'a';

  res[j] = '\0';

  return res;
}

int main()
{
  sprint("Hello!\n");

  char *res = longest("xyaabbbccccdefww", "xxxxyyyyabklmopq");

  sprint(res);

  // printf("%s", longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
}
