#include <stdio.h>
#include <stdlib.h>

int tickets(size_t length, const int people[length])
{
  int c25, c50, c100;
  c25 = c50 = c100 = 0;

  for (int i = 0; i < length && c25 > -1; i++)
    if (people[i] == 25)
      c25 += 1;
    else if (people[i] == 50)
      c25 -= 1, c50 += 1;
    else if (people[i] == 100)
      if (c50 > 0)
        c25 -= 1, c50 -= 1, c100 += 1;
      else
        c25 -= 3, c100 += 1;

  return c25 > -1;
}

int main()
{
  printf("%d\n", tickets(4, (int[]){25, 25, 50, 100, 50}));
}
