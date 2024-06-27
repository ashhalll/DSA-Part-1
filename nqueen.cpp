#include <iostream>
using namespace std;

// Function to check if placing a queen at (r, c) is valid
bool isPath(int** board, int r, int c, int n) {
    // Checking the column for any queens
    for (int i = r - 1; i >= 0; i--) {
        if (board[i][c] == 1) {
            return false;
        }
    }

    // Checking the upper left diagonal for any queens
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Checking the upper right diagonal for any queens
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to place queens recursively
void Queenplacer(int** board, int r, int c, int n) {
    // If all queens are placed successfully, print the solution
    if (r == n) {
        cout << "We have found a solution" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Try placing a queen in each column of the current row
    for (int j = 0; j < n; j++) {
        if (isPath(board, r, j, n)) {
            board[r][j] = 1; // Place a queen

            // Recursively try to place queens in the next row
            Queenplacer(board, r + 1, c, n);

            board[r][j] = 0; // Backtrack by removing the queen
        }
    }
}

// Function to initialize and call the Queenplacer function
void putQueen(int** board, int n) {
    Queenplacer(board, 0, 0, n);
    return;
}

int main() {
    // Create a 4x4 chessboard and initialize it
    int** board = new int*[4];
    for (int i = 0; i < 4; i++) {
        board[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }

    // Call the function to place queens
    putQueen(board, 4);

    // Deallocate memory
    for (int i = 0; i < 4; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
