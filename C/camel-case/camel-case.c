#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *camel_case(const char *s)
{
  char *res = (char *)(calloc(strlen(s), sizeof(char)));
  int space = 1;
  int j = 0;

  do
  {
    if (*s == ' ')
    {
      space = 1;
    }
    else
    {
      res[j++] = (space ? toupper(*s) : *s);
      space = 0;
    }
  } while (*s++ != '\0');

  res[j] = '\0';

  return res;
}

int main()
{
  printf("%s\n", camel_case("hello world"));
}
