#include <stdio.h>
#include <stddef.h>

const char *odd_or_even(const int *v, size_t sz)
{
  int sum = 0;
  for (int i = 0; i < (int)sz; i++)
    sum += v[i];

  return sum % 2 ? "odd" : "even";
}

int main()
{
  // Your code goes here...
}
