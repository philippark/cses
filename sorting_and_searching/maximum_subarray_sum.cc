/*
Idea:
If the current number is larger than the previous max accumulated sum,
then no need to bother. cut the burden and start the new subarray sum with the current number.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vll v(n);
    for (auto&x : v) {
        cin >> x;
    }

    ll sum = v[0];
    ll max_sum = sum;

    for (int i = 1; i < n; ++i) {
        sum = max(v[i], v[i]+sum);
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << "\n";
    
    return 0;
}