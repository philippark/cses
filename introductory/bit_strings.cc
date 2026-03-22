/*
Idea:
Just compute 2^n.
But using the library pow() leads to truncation errors, 
so just compute manually.
*/

#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    long long ret = 2;
    while (--n) {
        ret = (ret*2) % MOD;
    }

    cout << ret%MOD << "\n";

    return 0;
}