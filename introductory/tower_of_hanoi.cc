/*
Idea:
Move all the stones on top to another stack,
move the bottom-most stone to the R stack,
and then move the rest of the stack to the R stack.

Each stone follows this same strategy. We can recursively solve this.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string> vs;

#define PB push_back

vs moves;

ll move(int n, char start, char dest, char extra) {
    if (n == 0) {
        return 0;
    }

    ll ret = move(n-1, start, extra, dest) + 1;
    moves.PB(string(1, start) + " " + string(1, dest));
    ret += move(n-1, extra, dest, start);

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    move(n, '1', '3', '2');
    cout << moves.size() << "\n";
    for (auto move : moves) {
        cout << move << "\n";
    }

    return 0;
}