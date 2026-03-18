#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
#define PB push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vs v {"0", "1"};
    while (--n) {
        vs t1;
        vs t2;

        for (auto s : v) {
            t1.PB("0" + s);
            t2.PB("1" + s);
        }
        
        int size = t2.size();
        for (int i = size-1; i >= 0; --i) {
            t1.PB(t2[i]);
        }

        v = t1;
    }

    for (auto s : v) {
        cout << s << "\n";
    }

    return 0;
}