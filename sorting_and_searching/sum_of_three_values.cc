/*
Idea:
3sum. as you go through, you can lock one of the variables. 
then you are now solving for 2sum. however, using a map
is way too slow, instead you could have the array sorted and use a 
2pointer approach to finding the 2 other variables.

alternatively, you could try every combo of a,b and use binary search 
to find c. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, x;
    cin >> n >> x;

    pii arr[n];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr[i] = make_pair(x, i+1);
    }

    sort(arr, arr+n);

    for (int i = 2; i < n; ++i) {
        int x2 = x - arr[i].first;
        int L = 0, R = i-1;
        while (L < R) {
            int sum = arr[L].first + arr[R].first;
            if (sum == x2) {
                cout << arr[L].second << " " << arr[R].second << " " << arr[i].second << "\n";
                return 0;
            } else if (sum < x2) {
                ++L;
            } else {
                --R;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

}