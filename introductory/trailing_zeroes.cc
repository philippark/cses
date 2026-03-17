#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll mul = 5;
    int ret = 0;
    while (mul <= n) {
        ret += (n/mul);
        mul *= 5;
    }
    cout << ret << "\n";

    return 0;
}