#include <stdio.h>
#include <stdlib.h>

#define TAPELEN 5000

// void brainfuck(const char *code, const char *input, char *output)
// code - The Brainfuck program to be executed
// input - A stream of input bytes to the Brainfuck program being executed
// output - A writable character buffer large enough to hold the expected output of the
//          Brainfuck program being executed
// Your task: Execute the Brainfuck program with the given input, writing the program output
// to the output buffer provided as a NUL-terminated C-string
int brainfuck(const char *code, const char *input, char *output)
{
  int outlen = 0;

  char *tape = (char *)calloc(TAPELEN, sizeof(char));
  for (int i = 0; i < TAPELEN; i++)
    tape[i] = 0;

  int cursor = TAPELEN / 6;

  int loop = 0;
  int distance = 0;

  for (; *code != '\0'; code++)
  {
    distance += loop;

    switch (*code)
    {

    case '>':
      cursor++;
      break;

    case '<':
      cursor--;
      break;

    case '+':
      tape[cursor] = (tape[cursor] + 1) % 256;
      break;

    case '-':
      tape[cursor] = tape[cursor] == 0 ? (char)255 : tape[cursor] - 1;
      break;

    case '.':
      *output++ = tape[cursor];
      outlen++;
      break;

    case ',':
      tape[cursor] = *input++;
      break;

    case '[':
      if (tape[cursor])
        loop = 1;
      else
        while (tape[cursor] != ']')
          cursor++;
      break;

    case ']':
      if (tape[cursor])
        for (; distance >= 0; distance--)
          code--;
      else
        loop = 0, distance = 0;
      break;

    default:
      break;
    }
  }

  return outlen;
}

void aprint(int len, char *nums)
{
  for (int i = 0; i < len; i++)
    printf(i == len - 1 ? "%d\n" : "%d ", nums[i]);
}

int main()
{
  const char *code = ",>,[<+>-]<.";
  const char input[] = {17, 23};
  char output[10];

  int len = brainfuck(code, input, output);

  aprint(len, output);
}
