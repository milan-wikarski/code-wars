#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define INSIDE 0
#define OUTSIDE 1

void swap(char *text, int i, int j)
{
  char temp = text[i];
  text[i] = text[j];
  text[j] = temp;
}

int reverse(char *text, int from, int to)
{
  for (; from < to; from++, to--)
    swap(text, from, to);
}

char *reverseWords(char *text)
{
  char ch;
  int state = OUTSIDE;
  int start;
  int end;

  char *ntext = (char *)malloc(sizeof(*text) * strlen(text));
  strcpy(ntext, text);

  for (start = 0, end = 0; (ch = ntext[end]) != '\0'; end++)
  {
    if (isspace(ch))
    {
      if (state == INSIDE)
      {
        reverse(ntext, start, end - 1);
        state = OUTSIDE;
      }
    }
    else
    {
      if (state == OUTSIDE)
      {
        start = end;
        state = INSIDE;
      }
    }
  }

  if (start != end && state == INSIDE)
    reverse(ntext, start, end - 1);

  return ntext;
}

int main()
{
  char str[] = "Thi is an example!";
  printf("%s\n", str);

  reverseWords(str);
  printf("%s\n", str);
}