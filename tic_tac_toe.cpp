#include <iostream>
#include <string>
#include "tic_tac_toe.hpp"

void display_board(char board[3][3])
{
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

char check_rows(char board[3][3])
{
    int matches;
    char winner;

    for (int i = 0; i < 3; i++) {
        matches = 0;

        for (int j = 0; j < 2; j++) {
            if (board[i][j] == ' ')
                break;

            if (board[i][j] == board[i][j+1]) {
                winner = board[i][j];
                matches++;
            }
            else {
                break;
            }
        }

        if (matches == 2)
            return winner;
    }

    return '\0';
}

char check_columns(char board[3][3])
{
    int matches;
    char winner;

    for (int i = 0; i < 3; i++) {
        matches = 0;

        for (int j = 0; j < 2; j++) {
            if (board[j][i] == ' ')
                break;

            if (board[j][i] == board[j+1][i]) {
                winner = board[j][i];
                matches++;
            }
            else {
                break;
            }
        }

        if (matches == 2)
            return winner;
    }

    return '\0';
}

char check_diagonals(char board[3][3])
{
    if (board[1][1] == ' ')
        return '\0';

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return board[1][1];
    }

    return '\0';
}

char check_game_status(char board[3][3])
{
    char winner;

    winner = check_rows(board);
    if (winner != '\0')
        return winner;

    winner = check_columns(board);
    if (winner != '\0')
        return winner;

    winner = check_diagonals(board);
    if (winner != '\0')
        return winner;

    return '\0';
}

bool is_field_free(char field, char board[3][3])
{
    int counter = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            counter++;
            if (counter == field) {
                if (board[i][j] == ' ')
                    return true;
                
                break;
            }
        }
    }

    return false;
}

void input_sign(char player, char board[3][3])
{
    int field;
    int counter = 0;

    do {
        std::cout << "Player " << player << std::endl;
        std::cout << "Enter the field (1-9): ";
        std::cin >> field;
    } while (!is_field_free(field, board));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            counter++;
            if (counter == field) {
                board[i][j] = player;
                break;
            }
        }
    }
}

void run_game()
{
    char winner = '\0';
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    int turns = 0;

    do {
        display_board(board);

        input_sign(player, board);
        turns++;
        winner = check_game_status(board);

        player = player == 'X' ? 'O' : 'X';
    } while(winner == '\0' && turns < 9);

    display_board(board);

    if (winner == '\0')
        std::cout << "The game is a tie!" << std::endl;
    else
        std::cout << "The winner is " << winner << "!" << std::endl;

    return;
}

void tic_tac_toe_init() {
    std::cout << "Starting Tic Tac Toe..." << std::endl;

    run_game();

    return;
}
