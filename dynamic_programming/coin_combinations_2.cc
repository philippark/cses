/*
Idea:
1 pass per coin,
go through the coins in sorted order and count the ways
you can arrive at a certain sum with the specific coin.
this way, it's guaranteed you are adding to a pile of 
previous coins <= current coin.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define sort(a) sort(a.begin(), a.end())
#define M 1000000007

int main() {
    int n, x;
    cin >> n >> x;
    vi coins(n);
    for (auto&x : coins) {
        cin >> x;
    }
    sort(coins);

    vll v(x+1, 0);
    v[0] = 1;

    for (auto coin : coins) {
        for (int i = 1; i <= x; ++i) {
            if (i-coin >= 0)
                v[i] = v[i] + v[i-coin];
                v[i] %= M;
        }
    }

    cout << v[x] << "\n";

    return 0;
}