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

    multiset<ll> prefix;
    multiset<ll> suffix;

    int res1[n];
    int res2[n];

    sort(arr, [](const auto& a, const auto& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    });

    for (int i = 0; i < n; ++i) {
        int idx = arr[i][2];
        auto itr = prefix.lower_bound(arr[i][1]);
        // cout << arr[i][1] << " " << *itr << " " << distance(itr, prefix.end()) << "\n";
        res2[idx] = distance(itr, prefix.end());
        prefix.insert(arr[i][1]);
    }

    for (int i = n-1; i >= 0; --i) {
        // cout << arr[i][1] << "\n";
        int idx = arr[i][2];
        auto itr = suffix.upper_bound(arr[i][1]);
        // cout << arr[i][1] << " " << *itr << " " << distance(suffix.begin(), itr) << "\n";
        res1[idx] = distance(suffix.begin(), itr);
        suffix.insert(arr[i][1]);
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