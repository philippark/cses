/*
Idea:
sliding window

if there was a prev occurence, 
tighten the window to the last occurence 
(edge case: L is already beyond the last occurence,
in which case, move L to the max(L, last occurence index))
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vll v(n);
    for (auto& x : v) {
        cin >> x;
    }

    ll L = 0, R = 0, max_sum = 0, sum = 0;
    map<ll, ll> occurences;
    while (R < n) {
        if (occurences[v[R]]) {
            max_sum = max(max_sum, sum);
            ll new_L = max(L, occurences[v[R]]);
            sum -= new_L - L;
            L = new_L;
        }
        occurences[v[R]] = R+1;
        sum++;
        R++;
    }
    max_sum = max(max_sum, sum);

    cout << max_sum << "\n";
    
    return 0;
}