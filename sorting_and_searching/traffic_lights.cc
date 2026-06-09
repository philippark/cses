/*
given a position, it splits left nearest end and right nearest end.
(end being end of street of another lamplight).
can just take those, calculate the new ranges, and add to a data structure.

data structures to use can be a set to hold the positions,
and a multiset to hold the ranges.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;

#define PB push_back
#define sort(a, ...) sort(a.begin(), a.end(), ##__VA_ARGS__)
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define M 1000000007
#define INF 2147483647
#define INFL 9223372036854775807
#define MOD 998244353

int main() {
    int x, n;
    cin>>x>>n;

    vi v(n);
    for (auto&x : v) {
        cin>>x;
    }

    set<int> s;
    s.insert(0);
    s.insert(x);

    multiset<int> ms;
    ms.insert(x);

    for (int i = 0; i < n; ++i) {
        int p = v[i];

        auto left = s.lower_bound(p);
        --left;
        auto right = s.upper_bound(p);

        int prev_r = *right - *left;
        auto prev = ms.find(prev_r);
        if (prev != ms.end()) {
            ms.erase(prev);
        }

        int r1 = p-*left;
        int r2 = *right-p;

        ms.insert(r1);
        ms.insert(r2);

        s.insert(p);

        cout << *ms.rbegin() << " ";
    }
    cout << "\n";

    return 0;
}