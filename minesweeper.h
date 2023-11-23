#include <vector>
#include <iostream>

using std::vector;
using std::string;

#define TABLE_DIMENSION 4
#define NBOMBS 3

#define START "start"
#define REVEAL "reveal"
#define FLAG 2
#define STATE 3
#define REMOVE_FLAG 4
#define RESET "reset"
#define WIN 6
#define EXIT 7
#define GAME_OVER 8

#define BOMB -1
#define HIDDEN -2
#define FLAGGED -3

class Minesweeper
{
    private:
        int **current_board;
        int count_revealed;
        vector<vector<int>> answer_board_int;
        void game_over(string message);
        void start_new_game();
        

    public:
        Minesweeper();
        ~Minesweeper();
        
        void reveal(int x, int y);
        void flag(int x, int y);
        void remove_flag(int x, int y);
        void reset();
        void process_client_action(string action_received);
        void print_board();
        vector<vector<int>> mount_board(char *file);
};