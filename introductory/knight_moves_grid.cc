/*
Idea:
Bruteforce simulation. 
First pass: left to right, up to down
Second pass: right to left, down to up
Third pass is just first again to work out the kinks
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define PB push_back

void check(vvi& grid, int prev_i, int prev_j, int i, int j, int n) {
    if (prev_i < 0 || prev_i >= n || prev_j < 0 || prev_j >= n) {
        return;
    }

    grid[i][j] = min(grid[i][j], grid[prev_i][prev_j]+1);
}

void solve(int n) {
    vvi grid(n, vi(n, n+10));

    grid[0][0] = 0;
    grid[1][2] = 1;
    grid[2][1] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            check(grid, i-2, j-1, i, j, n);
            check(grid, i-2, j+1, i, j, n);
            check(grid, i-1, j-2, i, j, n);
            check(grid, i-1, j+2, i, j, n);
        }
    }

    for (int i = n-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
            check(grid, i+2, j+1, i, j, n);
            check(grid, i+2, j-1, i, j, n);
            check(grid, i+1, j+2, i, j, n);
            check(grid, i+1, j-2, i, j, n);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            check(grid, i-2, j-1, i, j, n);
            check(grid, i-2, j+1, i, j, n);
            check(grid, i-1, j-2, i, j, n);
            check(grid, i-1, j+2, i, j, n);
        }
    }
    
    for (auto i : grid) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    solve(n);

    return 0;
}