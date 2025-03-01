typedef struct QueenTracker QueenTracker;

QueenTracker *new_tracker(int board_area);
void free_tracker(QueenTracker *qt);
void feed_line(QueenTracker *qt, char *line, int lineno);

#ifdef __YOU_ARE_QUEEN
void debug_tracker(QueenTracker *qt);
#endif