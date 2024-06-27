#include <iostream>
using namespace std;

// Function to check if a cell is a valid path
bool isPath(int** board, int r, int c, int n) {
    if (r < n && c < n && board[r][c] == 1) {
        return true;
    }
    return false;
}

// Recursive function to find a path
bool recursive_path(int** board, int r, int c, int n, int** sol) {
    // If we have reached the destination
    if (r == n - 1 && c == n - 1) {
        sol[r][c] = 1; // Mark the destination as part of the path
        return true;
    }
    
    // If the current cell is a valid path
    if (isPath(board, r, c, n)) {
        sol[r][c] = 1; // Mark the current cell as part of the path
        
        // Try moving down
        if (recursive_path(board, r + 1, c, n, sol)) {
            return true;
        }
        
        // Try moving right
        if (recursive_path(board, r, c + 1, n, sol)) {
            return true;
        }
        
        sol[r][c] = 0; // If both directions didn't lead to a solution, backtrack
        return false;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    
    // Allocate memory for the board and solution matrices
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
    }
    
    // Input the maze
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    // Initialize the solution matrix with zeros
    int** sol = new int*[n];
    for (int i = 0; i < n; i++) {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++) {
            sol[i][j] = 0;
        }
    }
    
    // Call the recursive function to find the path
    if (recursive_path(board, 0, 0, n, sol)) {
        cout << "Path found" << endl;
        
        // Display the solution matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found" << endl;
    }
    
    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] board[i];
        delete[] sol[i];
    }
    delete[] board;
    delete[] sol;

    return 0;
}
