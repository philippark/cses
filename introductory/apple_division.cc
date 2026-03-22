/*
Idea:
WIthout the n <= 20 constraint, this is a NP hard problem.
There is no mathematical way to solve this, just have to explore every possibility. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define PB push_back

void explore(vll &v, int start, ll L, ll R, ll& ret) {
    if (start == v.size()) {
        if (R < 0 || L < 0) {
            return;
        }
        if (ret == -1) {
            ret = abs(R-L);
        }
        else ret = min(ret, abs(R-L));
        return;
    }

    explore(v, start+1, L+v[start], R, ret);
    explore(v, start+1, L, R+v[start], ret);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vll v(n);
    for (auto& x : v) {
        cin >> x;
    }

    ll ret = -1;
    explore(v, 0, 0, 0, ret);
    cout << ret << "\n";

    return 0;
}