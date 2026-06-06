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
    int n, x;
    cin>>n>>x;

    int ret = 0;
    vll v(n);
    for (auto&x : v) {
        cin>>x;
    }
    int L = 0, R = 0;
    ll sum = 0;

    while (R < n) {
        sum += v[R];
        while (sum > x) {
            sum -= v[L];
            ++L;
        }
        if (sum == x) {
            ++ret;
        }
        ++R;
    }

    cout << ret << "\n";

    return 0;
}