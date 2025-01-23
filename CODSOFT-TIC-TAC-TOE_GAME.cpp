#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>> &board);
bool isWin(const vector<vector<char>> &board, char player);
bool isDraw(const vector<vector<char>> &board);
void resetBoard(vector<vector<char>> &board);
void playerMove(vector<vector<char>> &board, char player);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 grid initialized with spaces
    char currentPlayer = 'X';
    bool playAgain = true;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (playAgain) {
        resetBoard(board);
        bool gameOver = false;

        while (!gameOver) {
            displayBoard(board);
            playerMove(board, currentPlayer);

            if (isWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (isDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
            }
        }

        char response;
        cout << "Do you want to play again? (y/n): ";
        cin >> response;
        playAgain = (response == 'y' || response == 'Y');
        currentPlayer = 'X'; // Reset to player X for new game
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}

// Function to display the current state of the board
void displayBoard(const vector<vector<char>> &board) {
    cout << "\nCurrent board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << (board[i][j] == ' ' ? '-' : board[i][j]);
            if (j < 2) cout << " |";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---\n";
    }
    cout << endl;
}

// Function to check if a player has won
bool isWin(const vector<vector<char>> &board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
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

// Function to check if the game is a draw
bool isDraw(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to reset the board for a new game
void resetBoard(vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to handle a player's move
void playerMove(vector<vector<char>> &board, char player) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << player << ", enter your move (row and column: 1-3 1-3): ";
        cin >> row >> col;

        // Validate input
        if (cin.fail() || row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid move. Please try again." << endl;
        } else {
            board[row - 1][col - 1] = player;
            validMove = true;
        }
    }
}
