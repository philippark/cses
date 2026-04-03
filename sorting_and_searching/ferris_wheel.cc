/*
Idea:
Try to pack as close to the limit as possible
So try to pair the largest with any other possible number, 
which could be the smallest
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define sort(a) sort(a.begin(), a.end())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vll v(n);
    for (auto&x : v) {
        cin >> x;
    } 
    sort(v);

    int L = 0, R = n-1, count=0;
    while (L <= R) {
        count++;
        if (v[L] <= (x - v[R])) {
            L++;
            R--;
        } else {
            R--;
        }
    }

    cout << count << "\n";

    return 0;
}