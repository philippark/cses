/*
Idea:
Fix 2 elements, and then use two pointers to find the other 2 elements.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i) {
        pair<int, int> p = make_pair(0, i);
        cin >> p.first;
        arr[i] = p; 
    }

    sort(arr, arr+n);

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int rem = x-arr[i].first-arr[j].first;
            int L = j+1, R = n-1;
            while (L < R) {
                int sum = arr[L].first+arr[R].first;
                if (sum==rem) {
                    cout << arr[i].second+1 << " " << arr[j].second+1 << " " << arr[L].second+1 << " " << arr[R].second+1 << "\n";
                    return 0;
                } else if (sum<rem) {
                    ++L;
                } else {
                    --R;
                }
            }
        }
    }    
    cout << "IMPOSSIBLE\n";
    return 0;
}