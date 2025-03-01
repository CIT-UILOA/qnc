#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

QueenTracker *new_tracker(int board_area)
{
  QueenTracker *qt = (QueenTracker *)malloc(sizeof(QueenTracker));

  if (qt == NULL)
  {
    return NULL;
  }

  // I dont think there will come a case
  // where we will need more than
  // a quarter of the board's area
  qt->queen_x = (int *)malloc(board_area / 4);
  qt->queen_y = (int *)malloc(board_area / 4);
  qt->capacity = board_area / 4;
  qt->len = 0;

  return qt;
}

void check_for_war(QueenTracker *qt)
{
  int a_x = 0, a_y = 0, b_x = 0, b_y = 0;

  size_t board_len = qt->len;

  if (board_len <= 1)
  {
    // Either the board is empty, or
    // there is only 1 queen on the board
    printf("SAFE");
    return;
  }

  for (int coord_a = 0; coord_a < board_len; coord_a++)
  {
    a_x = qt->queen_x[coord_a];
    a_y = qt->queen_y[coord_a];

    for (int coord_b = 0; coord_b < board_len; coord_b++)
    {
      // skip checking if the compared (coord b)
      // is the same as coord a
      if (coord_a == coord_b)
      {
        continue;
      }

      b_x = qt->queen_x[coord_b];
      b_y = qt->queen_y[coord_b];

      // if ax and bx OR
      // ay and by are the same
      if (a_x == b_x || a_y == b_y)
      {
        printf("WAR (Horizontal or Vertical)");
        return;
      } // ... or...BASTA OI KANI!!!
      else if (abs(a_x - b_x) == abs(a_y - b_y))
      {
        printf("WAR (Diagonal)");
        return;
      }
    }
  }
  printf("SAFE");
}

void free_tracker(QueenTracker *qt)
{
  // Gotta free these. Again, won't be instantiating
  // a lof of these but still good practice, no?
  free(qt->queen_x);
  free(qt->queen_y);
  free(qt);
}

void grow_tracker_buffers(QueenTracker *qt)
{
  int new_cap = qt->capacity * 2;

  qt->queen_x = realloc(qt->queen_x, new_cap);
  qt->queen_y = realloc(qt->queen_y, new_cap);

  qt->capacity = new_cap;
}

void push_coordinates(QueenTracker *qt, int x, int y)
{
  if (qt->len == qt->capacity)
  {
    grow_tracker_buffers(qt);
  }

  int current_index = qt->len;
  qt->queen_x[current_index] = x;
  qt->queen_y[current_index] = y;

  qt->len++;
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

// Debugging stuff
void debug_tracker(QueenTracker *qt)
{
  int len = qt->len, current_x = 0, current_y = 0;

  printf("%d coordinates listed in tracker:\n", len);
  for (int i = 0; i < len; i++)
  {
    current_x = qt->queen_x[i];
    current_y = qt->queen_y[i];

    printf("\t[%d] (%d, %d)\n", i, current_x, current_y);
  }
}
