#ifndef BOARD_H
#define BOARD_H
void draw_board(const char* board,int pos);// draw board,and respond to user input and move cursor
void find_next_best_move(char* board);// compute and make the best possible move in a position
#endif

