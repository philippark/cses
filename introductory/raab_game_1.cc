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
    int t;
    cin>>t;
    while(t--) {
        int n, a, b;
        cin>>n>>a>>b;

        if (a+b > n || (a==0 && b>0) || (b==0 && a>0)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

        int d = n-(a+b);
        for (int i = 1; i <= n; ++i) cout << i << " ";
        cout << "\n";

        for (int i = 1; i <= d; ++i) cout << i << " ";
        for (int i = d+a+1; i <= n; ++i) cout << i << " ";
        for (int i = d+1; i <= d+a; ++i) cout << i << " ";
        cout << "\n";
    }

    return 0;
}