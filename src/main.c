#define BOARD_SIZE 8
#define BUFFER_SIZE BOARD_SIZE + 2
#define __YOU_ARE_QUEEN

#include <stdio.h>
#include <string.h>
#include "queen.h"

int main()
{
  QueenTracker *qt = new_tracker(BOARD_SIZE);

  if (qt == NULL)
  {
    perror("Unable to initialize queen tracker");
    return 1;
  }

  FILE *input = fopen("input", "r");
  if (input == NULL)
  {
    perror("Unable to open input file");
    // input = stdin;
    return 1;
  }

  char buf[BUFFER_SIZE];
  memset(&buf, 0, BUFFER_SIZE);

  int lineno = 0;
  while (fgets(buf, BUFFER_SIZE, input) != NULL)
  {
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n')
    {
      buf[len - 1] = '\0';
    }
    printf("%d %s\n", lineno++, buf);

    feed_line(qt, buf, lineno);
    debug_tracker(qt);
  };

  fclose(input);
  free_tracker(qt);
}