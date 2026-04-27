/*
Idea:
if sorted by the 1st element,
to check if a current entry can be contained:
just need to check in the left for a 2nd element >= current 2nd element

to check if can contain:
just need to check in the right for a 2nd element <= current 2nd element

utilize prefix and suffix to hold the min and max,
sort by 2nd element desc for edge cases of same 1st element
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define sort(a, ...) sort(a.begin(), a.end(), ##__VA_ARGS__)

int main() {
    int n;
    cin >> n;

    vvll arr(n, {0,0,0});
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }

    vll prefix(n);
    prefix[0] = 0;
    vll suffix(n);
    suffix[n-1] = 1e9 + 1;

    int res1[n];
    int res2[n];

    sort(arr, [](const auto& a, const auto& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    });

    for (int i = 1; i < n; ++i) {
        prefix[i] = max(prefix[i-1], arr[i-1][1]);
    }
    for (int i = n-2; i >= 0; --i) {
        suffix[i] = min(suffix[i+1], arr[i+1][1]);
    }

    for (int i = 0; i < n; ++i) {
        int idx = arr[i][2];
        res1[idx] = arr[i][1] >= suffix[i];
        res2[idx] = arr[i][1] <= prefix[i];
    }

    for (auto x : res1) {
        cout << x << " ";
    }
    cout << "\n";
    for (auto x : res2) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}