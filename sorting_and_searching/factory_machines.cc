/*
Idea:
Binary search on the time.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    ll n, t;
    cin >> n >> t;

    vll machines(n);
    for (auto&x : machines) {
        cin >> x;
    }

    ll L = 0, H = *min_element(machines.begin(), machines.end()) * t;

    while (L <= H) {
        ll mid = L + (H-L) / 2;
        ll sum = 0;
        for (auto& x : machines) {
            sum += mid/x;
            if (sum >= t) break;
        }

        if (sum >= t) {
            H = mid-1;
        } else {
            L = mid+1;
        }
    }

    cout << L << "\n";

    return 0;
}