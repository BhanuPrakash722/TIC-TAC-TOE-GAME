#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;


void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--|---|--\n";
    }
    cout << "\n";
}


bool checkWin(const vector<vector<char>>& board, char player) {

    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }


    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}


void getPlayerMove(int& row, int& col, char currentPlayer) {
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column: 1 1 for top-left): ";
        cin >> row >> col;


        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter numbers for row and column.\n";
            continue;
        }


        break;
    }
}


int main() {
    char playAgain;
    do {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';

        cout << "Welcome to Tic-Tac-Toe!\n";

        while (true) {
            displayBoard(board);
            int row, col;


            getPlayerMove(row, col, currentPlayer);


            row--; col--;


            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move. The cell is either out of bounds or already occupied. Try again.\n";
                continue;
            }


            board[row][col] = currentPlayer;


            cout << "Player " << currentPlayer << " made a move at position (" << row + 1 << ", " << col + 1 << ").\n";


            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }


            if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                break;
            }


            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}
