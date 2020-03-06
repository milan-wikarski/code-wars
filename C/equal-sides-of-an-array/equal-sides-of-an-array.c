#include <stdio.h>

int find_even_index(const int *values, int length)
{
  int prefix[length];
  prefix[0] = values[0];
  for (int i = 1; i < length; i++)
    prefix[i] = prefix[i - 1] + values[i];

  if (prefix[length - 1] - prefix[0] == 0)
    return 0;

  for (int i = 1; i < length; i++)
    if (prefix[length - 1] - prefix[i] == prefix[i - 1])
      return i;

  return -1;
}

int main()
{
  // Your code goes here...
}
