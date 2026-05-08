/*
Idea:
greedy. we want to select movies that end as early as possible, 
because this leaves the most room for the rest of the movies. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    int n;
    cin >> n;
    pair<ll, ll> arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr+n);

    ll last_pos = -1;
    ll ret = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i].second >= last_pos) {
            last_pos = arr[i].first;
            ++ret;
        }
    }    

    cout << ret << "\n";

    return 0;
}