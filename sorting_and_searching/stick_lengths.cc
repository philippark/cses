/*
Idea:
the largest and smallest numbers eventually have to converge.
so the distance between each largest and smallest pair is the minimum / bottleneck
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define sort(a) sort(a.begin(), a.end());

int main() {
    int n;
    cin >> n;
    vll v(n);
    for (auto&x : v) {
        cin >> x;
    }

    sort(v);

    ll L = 0, R = n-1, count = 0;
    while (L<=R) {
        ll diff = v[R]-v[L];
        count += diff;
        L++;
        R--; 
    }

    cout << count << "\n";

    return 0;
}