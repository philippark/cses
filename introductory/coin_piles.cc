#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        /*
        a = 2x + y
        b = x + 2y

        y = (a-2b)/-3
        x = (2a-b)/3
        */

        ll t1 = a-(2*b);
        ll t2 = (2*a)-b;
        if ((t1%3)==0 || (t2%3)==0) {
            if ((t1/-3)>=0 && (t2/3)>=0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}