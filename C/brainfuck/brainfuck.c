#include <stdio.h>
#include <stdlib.h>

#define TAPELEN 5000

#define printnums(a, l)       \
  for (int i = 0; i < l; i++) \
    printf(i == l - 1 ? "%d\n" : "%d ", a[i]);

#define strprint(a)                  \
  for (int i = 0; a[i] != '\0'; i++) \
    putchar(a[i]);

int brainfuck(const char *code, const char *input, char *output)
{
  int outlen = 0;

  char *tape = (char *)calloc(TAPELEN, sizeof(char));
  for (int i = 0; i < TAPELEN; i++)
    tape[i] = 0;

  int *loop_stack = (int *)calloc(100, sizeof(int));

  int code_cursor = 0;
  int tape_cursor = 0;
  int loop_cursor = 0;

  for (; code[code_cursor] != '\0'; code_cursor++)
  {
    switch (code[code_cursor])
    {

    case '>':
      tape_cursor++;
      break;

    case '<':
      tape_cursor--;
      break;

    case '+':
      tape[tape_cursor] = (tape[tape_cursor] + 1) % 256;
      break;

    case '-':
      tape[tape_cursor] = tape[tape_cursor] == 0 ? (char)255 : tape[tape_cursor] - 1;
      break;

    case '.':
      *output++ = tape[tape_cursor];
      outlen++;
      break;

    case ',':
      tape[tape_cursor] = *input++;
      break;

    case '[':
      if (tape[tape_cursor])
      {
        loop_stack[loop_cursor++] = code_cursor;
      }
      else
        while (tape[tape_cursor] != ']')
          tape_cursor++;
      break;

    case ']':
      if (tape[tape_cursor])
      {
        code_cursor = loop_stack[loop_cursor - 1];
      }
      else
        loop_cursor--;
      break;

    default:
      break;
    }
  }

  return outlen;
}

int main()
{
  // const char *code = ",>,[<+>-]<.";
  const char *code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  strprint(code);
  putchar('\n');

  const char input[] = {17, 23};
  char output[100];

  int len = brainfuck(code, input, output);

  // printnums(output, len);
  strprint(output);
}
