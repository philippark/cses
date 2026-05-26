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

ll traverse(vll& v, ll a, ll b, ll base) {
    a += base;
    b += base;

    ll min_v = INFL;
    while (a <= b) {
        if (a % 2 == 1) {
            min_v = min(min_v, v[a-1]);
            a++;
        }
        if (b % 2 == 0) {
            min_v = min(min_v, v[b-1]);
            b--;
        }
        a /= 2;
        b /= 2;
    }

    return min_v;
}

int main() {
    ll n, q;
    cin >> n >> q;
    ll orig_n = n;

    ll p = 1;
    while (p < orig_n) {
        p *= 2;
    }

    ll size = p;
    for (ll i = p / 2; i >= 1; i /= 2) {
        size += i;
    }

    vll v(size, INFL);
    
    for (ll i = 0; i < orig_n; ++i) {
        ll x = p + i;
        cin >> v[x-1];
    }

    for (ll i = size - p; i > 0; --i) {
        v[i-1] = min(v[(2*i)-1], v[(2*i + 1)-1]);
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ll min_v = traverse(v, a, b, p);
        cout << min_v << "\n";
    }

    return 0;
}