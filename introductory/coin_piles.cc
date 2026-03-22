/*
Idea:
Solve the equation.

Let the first pile be "a", and the second be "b".
a = 2x + y
b = x + 2y
Where x is the number of times a coin is added twice to a and once to b
and y is the number of times a coin is added once to b and twice to a

y = (a-2b)/-3
x = (2a-b)/3

If it's possible, the x and y values must be >= 0.
Otherwise, it's impossible.
*/

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