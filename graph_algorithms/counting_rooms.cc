/*
Idea:
Everytime you encounter a room, dfs it and erase the room altogether.
that way, you count once each time.
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(vvc &grid, int i, int j) {
    grid[i][j] = '#';

    for (auto& move : moves) {
        int new_i = i + move[0];
        int new_j = j + move[1];

        if (new_i < 0 || new_i >= grid.size() || new_j < 0 || new_j >= grid[0].size()) {
            continue;
        }
        if (grid[new_i][new_j] == '.') {
            dfs(grid, new_i, new_j);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vvc grid(n, vc(m));
    for (auto&r : grid) {
        for (auto&c : r) {
            cin >> c;
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                ++rooms;
                dfs(grid, i, j);
            }
        }
    }

    cout << rooms << "\n";

    return 0;
}