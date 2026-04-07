/*
Idea:
Have to find the number of subsequences of consecutive numbers
If we pair the number and its index then sort, we can do that easily in O(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define sort(a) sort(a.begin(), a.end())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vvi v(n);
    int idx = 0;
    for (auto&v2 : v) {
        int x;
        cin >> x;
        v2 = {x, idx};
        ++idx;
    }

    sort(v);
    
    int ops = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i][1] < v[i-1][1]) {
            ++ops;
        }
    }
    ++ops;
    
    cout << ops << "\n";
    
    return 0;
}