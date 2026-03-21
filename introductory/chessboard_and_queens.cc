#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define PB push_back 

bool can_place(int r, int c, vvi& placed) {
    for (auto v : placed) {
        if (v[0] == r || v[1] == c) {
            return false;
        }

        if (abs(r-v[0]) == abs(c-v[1])) {
            return false;
        }
    }

    return true;
}

int explore(vs& grid, int start_row, vvi& placed, int q) {
    if (q == 0) {
        return 1;
    }
    
    int ret = 0;
    for (int i = start_row; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (grid[i][j] == '*'){
                continue;
            }
            
            if (can_place(i, j, placed)) {
                placed.PB({i, j});
                ret += explore(grid, i+1, placed, q-1);
                placed.pop_back();
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vs grid(8);
    for (auto &r : grid) {
        cin >> r;
    }

    vvi placed;
    int ret = explore(grid, 0, placed, 8);

    cout << ret << "\n";

    return 0;
}