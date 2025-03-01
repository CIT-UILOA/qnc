#include <stdlib.h>
#include <string.h>

typedef struct
{
  // too lazy to write 'unsigned short'
  // istg why cant they just make it
  // `u8` instead?
  int capacity;
  int len;
  int *queen_x;
  int *queen_y;
} QueenTracker;

void new_tracker(QueenTracker *qt, int board_area)
{
  // I dont think there will come a case
  // where we will need more than
  // a quarter of the board's area
  qt->queen_x = (int *)malloc(board_area / 4);
  qt->queen_y = (int *)malloc(board_area / 4);
  qt->capacity = board_area / 4;
  qt->len = 0;
}

void free_tracker(QueenTracker *qt)
{
  // Gotta free these. Again, won't be instantiating
  // a lof of these but still good practice, no?
  free(qt->queen_x);
  free(qt->queen_y);
}

void feed_line(QueenTracker *qt, char *line, int lineno) // idk how to describe this. lineno also serves as the y-coordinate
{
  size_t line_len = strlen(line);

  // colno is our x-coordinate, just wanted to keep
  // consistency since i named the other lineno
  for (int colno = 0; colno < line_len; colno++)
  {
    if (line[colno] == 'Q')
    {
      push_coordinates(qt, colno, lineno);
    }
  }
}

void push_coordinates(QueenTracker *qt, int x, int y)
{
  if (qt->len == qt->capacity)
  {
    qt_grow(qt);
  }

  int current_index = qt->len;
  qt->queen_x[current_index] = x;
  qt->queen_y[current_index] = y;

  qt->len++;
}

void qt_grow(QueenTracker *qt)
{
  int new_cap = qt->capacity * 2;

  realloc(qt->queen_x, new_cap);
  realloc(qt->queen_y, new_cap);

  qt->capacity = new_cap;
}