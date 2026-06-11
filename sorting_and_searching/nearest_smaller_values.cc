/*
as you got through the numbers:
for a current number,
if a number previous to current is greater, it is no longer
important because we have a new right most current number that is smaller.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;

typedef pair<int, int> pii;

#define PB push_back
#define sort(a, ...) sort(a.begin(), a.end(), ##__VA_ARGS__)
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define M 1000000007
#define INF 2147483647
#define INFL 9223372036854775807
#define MOD 998244353

int main() {
    int n;
    cin>>n;
    
    vi v(n);
    for (auto&x : v) {
        cin>>x;
    }

    stack<pii> st;
    vi ans(n, 0);

    for (int i = 0; i < n; ++i) {
        int x = v[i];
        while (!st.empty()) {
            pii y = st.top();
            if (y.first >= x) {
                st.pop();
            } else {
                ans[i] = y.second+1;
                break; 
            }
        }

        st.push({x, i});
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}