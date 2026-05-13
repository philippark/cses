/*
Idea:
The largest book is the bottleneck.
If the largest book takes longer to read than all the rest of the books
combined, then it'll always take 2*largest book length.
If not, then it can all be read sequentially without any blockage, so it's
just the total time to read all the books. 
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

int main() {
    int n;
    cin >> n;

    vll v(n);
    ll sum = 0;
    for (auto&x : v) {
        cin >> x;
        sum += x;
    }
    ll largest_book = *max_element(v.begin(), v.end());

    if (sum-largest_book >= largest_book) {
        cout << sum << "\n";
    } else {
        cout << 2 * largest_book << "\n";
    }

    return 0;
}