#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n%2 == 0) {
        if ((n/2)%2 != 0) {
            cout << "NO\n";
            return 0;
        }
    }
    else {
        if (((n+1)/2)%2 != 0) {
            cout << "NO\n";
            return 0;
        }
    }

    int L = 1, R = n;

    vector<vector<int>> v {{}, {}};
    if (R%2 !=0) {
        v[0].push_back(R);
        R--;
    }
    
    while (L < R) {
        v[L%2].push_back(L);
        v[L%2].push_back(R);
        L+=1;
        R-=1;
    }

    cout << "YES\n";
    cout << v[0].size() << "\n";
    for (auto i : v[0]) {
        cout << i << " ";
    }
    cout << "\n";
    cout << v[1].size() << "\n";
    for (auto i : v[1]) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}