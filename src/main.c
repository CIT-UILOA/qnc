#include <stdio.h>
#include <string.h>
#define BOARD_SIZE 10

int main()
{
  FILE *input = fopen("input", "r");
  if (input == NULL)
  {
    perror("Unable to open input file");
    return 1;
  }

  char buf[BOARD_SIZE];
  memset(&buf, 0, BOARD_SIZE);

  int lineno = 0;
  while (fgets(buf, BOARD_SIZE, input) != NULL)
  {
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n')
    {
      buf[len - 1] = '\0';
    }
    printf("%d %s\n", lineno++, buf);
  };

  fclose(input);
}