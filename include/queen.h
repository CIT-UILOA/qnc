typedef struct QueenTracker QueenTracker;

void new_tracker(QueenTracker *qt, int board_area);
void free_tracker(QueenTracker *qt);
void feed_line(QueenTracker *qt, char *line, int lineno);
