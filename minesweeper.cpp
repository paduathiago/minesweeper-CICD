#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include "minesweeper.h"

using namespace std;

Minesweeper::Minesweeper(string file)
{
    this->file = file;
    count_revealed = 0;
    answer_board = mount_board();
    start_new_game();
    print_board();
}

Minesweeper::~Minesweeper() {}

int Minesweeper::get_count_revealed()
{
    return count_revealed;
}

vector<vector<int>> Minesweeper::get_current_board()
{
    return current_board;
}

vector<vector<int>> Minesweeper::get_answer_board()
{
    return answer_board;
}

vector<vector<int>> Minesweeper::mount_board()
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
    current_board = vector(TABLE_DIMENSION, vector<int>(TABLE_DIMENSION, -2));
    cout << "Starting new game" << endl;
}

void Minesweeper::print_board()
{
    for (int i = 0; i < TABLE_DIMENSION; i++)
    {
        for (int j = 0; j < TABLE_DIMENSION; j++)
        {
            if (current_board[i][j] == HIDDEN)
                cout << "- ";

            else if (current_board[i][j] == FLAGGED)
                cout << "> ";
            else
                cout << current_board[i][j] << ' ';
        }
        cout << endl;
    }
}

void Minesweeper::game_over(string message)
{
    cout << message << endl;
    // print answer board
}

void Minesweeper::reveal(int x, int y)
{
    int revealed_cell = answer_board[x][y];
    
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
    print_board();
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