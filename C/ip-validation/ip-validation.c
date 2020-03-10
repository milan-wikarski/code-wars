#include <stdio.h>

int is_valid_ip(const char *addr)
{
  int n = 0;
  int dots = 0;
  int nlen = 0;

  for (;; addr++)
  {
    if (*addr == '.' || *addr == '\0')
    {
      if (nlen == 0 || n < 0 || n > 255)
        return 0;

      dots++;
      n = 0;
      nlen = 0;

      if (*addr == '.')
        continue;
      else
        break;
    }

    if (*addr < '0' || *addr > '9')
      return 0;

    if (*addr == '0' && n == 0)
      return 0;

    n = 10 * n + *addr - '0';
    nlen++;
  }

  return dots == 4;
};

int main()
{
  const char *valid_ip = "123.45.67.89";
  const char *invalid_ip = "123.045.067.089";

  printf("%s --> %d\n", valid_ip, is_valid_ip(valid_ip));
  printf("%s --> %d\n", invalid_ip, is_valid_ip(invalid_ip));
}
