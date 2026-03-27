/*
Idea: Narrow down the search. 
1) Find what type of number this position is (how many digits)
2) Find the specific number
3) Find the digit position of the specific number

Observe that each digit range multiplies by 10:
1-9: 9 numbers
10-99: 90 numbers
100-999: 900 numbers

We can find what digit number we are dealing with by trying to find which
range it fits in. 

Subtract, and we are given the remainder that we can use to find
which specific number in that range we are looking for.

We can use division and modulo to find the specific number, and the 
digit position in that number.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll k;
    cin >> k;

    ll range = 9;
    ll digits = 1;
    while (true) {
        if (k - (range * digits) <= 0) {
            break;
        }
        k -= (range * digits);
        range *= 10;
        digits++;
    }
    
    ll start_num = range / 9;
    k--;

    ll num = start_num + (k / digits);
    ll pos = k % digits;

    cout << to_string(num)[pos] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}