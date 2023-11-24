#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include "minesweeper.h"

using namespace std;

Minesweeper::Minesweeper()
{
    count_revealed = 0;
}

Minesweeper::~Minesweeper() {}

vector<vector<int>> Minesweeper::mount_board(string file)
{
    ifstream table_input(file); // Nome do arquivo de entrada

    vector<vector<int>> board(TABLE_DIMENSION, vector<int>(TABLE_DIMENSION));

    for (int i = 0; i < TABLE_DIMENSION; i++) 
    {
        string line;
        getline(table_input, line);

        stringstream ss(line);

        for (int j = 0; j < TABLE_DIMENSION; j++) 
        {
            string cell;
            getline(ss, cell, ',');

            stringstream converter(cell);
            converter >> board[i][j];
        }
    }
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