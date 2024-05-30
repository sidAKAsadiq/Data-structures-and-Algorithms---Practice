#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_safe(int** maze, int** path, int row, int col, int n) {
    // Bound checking
    if (row < 0 || row >= n || col < 0 || col >= n) {
        return false;
    }
    // Cell checking
    if (maze[row][col] == 0) {
        return false;
    }
    // Visited checking
    if (path[row][col] == 1) {
        return false;
    }
    return true;
}

void solve(int** maze, int** path, int row, int col, vector<string>& ans, int n, string sol) {
    // Base case - Destination reached
    if (row == n - 1 && col == n - 1) {
        ans.push_back(sol);
        return;
    }
    path[row][col] = 1;

    // Down
    if (is_safe(maze, path, row + 1, col, n)) {
        solve(maze, path, row + 1, col, ans, n, sol + 'D');
    }
    // Left
    if (is_safe(maze, path, row, col - 1, n)) {
        solve(maze, path, row, col - 1, ans, n, sol + 'L');
    }
    // Right
    if (is_safe(maze, path, row, col + 1, n)) {
        solve(maze, path, row, col + 1, ans, n, sol + 'R');
    }
    // Up
    if (is_safe(maze, path, row - 1, col, n)) {
        solve(maze, path, row - 1, col, ans, n, sol + 'U');
    }

    path[row][col] = 0;
}

int main() {
    int n = 4; // Size of the maze
    int** maze = new int*[n];
    int** path = new int*[n];
    vector<string> ans;
    string sol = "";

    for (int i = 0; i < n; i++) {
        maze[i] = new int[n];
        path[i] = new int[n];
    }

    cout << "Fill maze array: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            path[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    solve(maze, path, 0, 0, ans, n, sol);
    cout << "Possible solutions: \n";

    for (int i = 0; i < ans.size(); i++) { // Change the loop condition to use '<' instead of '<='
        cout << ans[i] << endl;
    }

    return 0;
}
