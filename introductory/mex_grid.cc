#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<int, bool> umb;
typedef vector<umb> vumb;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n;
    cin >> n;

    vumb aboves(n);
    vumb lefts(n);
    vvi grid(n, vi(n));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int i = 0;
            while(true) {
                if (!aboves[c][i] && !lefts[r][i]) {
                    grid[r][c] = i;
                    lefts[r][i] = true;
                    aboves[c][i] = true;
                    break;
                }
                i++;
            }
        }
    }

    for (auto i : grid) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}