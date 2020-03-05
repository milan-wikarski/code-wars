#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num)
{
  if (num < 2)
    return false;

  for (int div = 2; div < num; div++)
    if (num % div == 0)
      return false;

  return true;
}

int main()
{
  // Your code goes here...
}
