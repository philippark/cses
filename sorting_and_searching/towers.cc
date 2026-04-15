/*
Idea:
Choose to add to the stack with the minimum difference
this is to preserve space. A greedy + binary searching solution.

1st attempt: binary search
2nd attempt: multiset
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int arr[n];
    for (auto&x : arr) {
        cin >> x;
    }

    multiset<int> ms;
    int piles = 0;
    for (int i = 0; i < n; ++i) {
        auto it = ms.upper_bound(arr[i]);
        if (it != ms.end()) {
            ms.erase(it);
            ms.insert(arr[i]);
        } else {
            ms.insert(arr[i]);
            ++piles;
        }
    }

    cout << piles << "\n";

    return 0;
}