/*
Idea:
sliding window
for current number, count the number of subarrays with this specific number. 
that is R-L+1
but we need to shrink the window so that there are no duplicates. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll arr[n];
    for (auto&x : arr) cin >> x;

    map<ll, int> freq;
    int L = 0, R = 0;
    ll count = 0;
    while (R < n) {
        ++freq[arr[R]];

        while (freq[arr[R]] > 1) {
            --freq[arr[L]];
            ++L;
        }

        count += (R-L+1);
        ++R;
    }

    cout << count << "\n";

    return 0;
}