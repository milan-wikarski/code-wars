#include <stdio.h>
#include <stddef.h>

size_t countBits(unsigned value)
{
  size_t count = 0;
  int mask = 1;

  while (mask < (value * 2))
  {
    if ((value & mask) > 0)
      count++;

    mask = mask << 1;
  }

  return count;
}

int main()
{
  printf("%ld\n", countBits(1234));
}
