/*
Idea:
Choose to add to the stack with the minimum difference
this is to preserve space. A greedy + binary searching solution.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define PB push_back

int bin_search(vll& v, int t) {
    int L = 0, R = v.size()-1;
    while (L <= R) {
        int mid = L + (R-L)/2;
        if (v[mid] <= t) {
            L = mid+1;
        } else {
            R = mid-1;
        }
    }

    if (R < 0) return 0;
    if (L >= v.size()) return v.size();

    if (v[R] > t) {
        return R;
    } 
    return L;
}

int main() {
    int n;
    cin >> n;

    vll v;
    for (int i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        if (v.size()==0) {
            v.push_back(k);
            continue;
        }

        int idx = bin_search(v, k);
    
        if (idx == v.size()) {
            v.PB(k);
        } else {
            swap(v[idx], k);
        }
    } 

    cout << v.size() << "\n";

    return 0;
}