#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "minesweeper.h"

using namespace std;

Minesweeper::Minesweeper()
{
    count_revealed = 0;
}

Minesweeper::~Minesweeper()
{
    //destructor
}

vector<vector<int>> Minesweeper::mount_board(char * file)
{
    vector<vector<int>> board;

    FILE *table_input = fopen(file, "r");
    if (table_input == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < TABLE_DIMENSION; i++)
        for (int j = 0; j < TABLE_DIMENSION; j++)
            fscanf(table_input, "%d,", &board[i][j]);

    fclose(table_input);
    return board;
}

void Minesweeper::start_new_game()
{
    count_revealed = 0;
    for (int i = 0; i < TABLE_DIMENSION; i++)
    {
        for (int j = 0; j < TABLE_DIMENSION; j++)
            current_board[i][j] = HIDDEN;
    }
    cout << "Starting new game" << endl;
    // print current board
}

void Minesweeper::game_over(string message)
{
    cout << message << endl;
    // print answer board
}

void Minesweeper::reveal(int x, int y)
{
    int revealed_cell = answer_board_int[x][y];
    
        if(revealed_cell == BOMB)
        {
            game_over("You lost");
            count_revealed = 0;
        }
        else
        {
            current_board[x][y] = revealed_cell;
            count_revealed++;

            if(count_revealed == (TABLE_DIMENSION * TABLE_DIMENSION) - NBOMBS)
                game_over("You won!");
        }  
}

void Minesweeper::flag(int x, int y)
{
    current_board[x][y] = FLAG;
}

void Minesweeper::remove_flag(int x, int y)
{
    current_board[x][y] = HIDDEN;
}

void Minesweeper::reset()
{
    start_new_game();
}

void Minesweeper::process_client_action(string action_received)
{
    if (action_received == RESET)
        reset();

    if (action_received == START)
        start_new_game();
}

int main()
{

    return 0;
}