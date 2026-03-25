/*
Idea:
just select a character by checking against the previously committed values
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vvc grid(n, vc(m, '_'));
    for (auto& r : grid) {
        for (auto& c : r) {
            cin >> c;
        }
    }

    vc choices = {'A', 'B', 'C', 'D'};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (auto c : choices) {
                if (i-1 >= 0 && grid[i-1][j] == c) {
                    continue;
                }
                if (j-1 >= 0 && grid[i][j-1] == c) {
                    continue;
                }
                if (grid[i][j] == c) continue;

                grid[i][j] = c;
                break;
            }
        }
    }

    for (auto r : grid) {
        for (auto c : r) {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}