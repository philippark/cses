/*
Idea:
if we assume given a current num that all nums prev to it are creatable,
then adding curr num can only elevate all the previous.
For example:
1, 2, 3, +3
1+3=4, 2+3=5, 3+3=6

but we can never close the gap between the current num to add, and the previous.
so if theres a gap between the curr num and the accumulated sum so far,
then the lowest we can't create is sum+1
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define sort(a) sort(a.begin(), a.end())

int main() {
    int n;
    cin >> n;

    vll v(n);
    for (auto&x : v) {
        cin >> x;
    }

    sort(v);

    ll sum = 0;

    for (auto i : v) {
        if (i <= (sum+1)) {
            sum += i;
        } else {
            break;
        }
    }

    cout << sum+1 << "\n";
    
    return 0;
}