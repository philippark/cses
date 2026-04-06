/*
Idea:
Classic dp. 
If each number stored the number of ways it could have been constructed,
then given a current number, we know its number of ways by adding up 
the previous ways + a certain dice roll. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vll v(n+1, 0);
    v[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i-j < 0) break;
            v[i] = v[i] + v[i-j] % MOD;
        }
    }

    cout << v[n] % MOD << "\n";

    return 0;
}