#include <stdio.h>
#include <string.h>
#define BOARD_SIZE 9

int main()
{
  FILE *input = fopen("input", "r");
  char buf[BOARD_SIZE];
  memset(&buf, 0, BOARD_SIZE);

  fgets(&buf, BOARD_SIZE, input);

  fclose(input);
}