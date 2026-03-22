/*
Idea:
Reminded me of the story of the mathematician Gauss. 
As a child he was asked to solve the summation of 1...100,
and he used this observation:
1,2,3,4,5,6,7

1+7=8
2+6=8
3+5=8

Essentially, left and right ints added are always the same,
because we are adding 1 to the left, and subtracting 1 from the right.

However, we must come up with 2 sets of equal sums.
So if the number is odd, we start with the left as 0.

0+7=7
1+6=7
2+5=7
3+4=7
*/

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