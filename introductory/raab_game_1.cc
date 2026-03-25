#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define PB push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, a_w, b_w;
        cin >> n >> a_w >> b_w;

        int d = n - (a_w + b_w);

        if (d < 0) {
            cout << "NO\n";
            continue;
        }

        int a_l = n - (a_w + d);
        int b_l = n - (b_w + d);
       
        cout << "-------\n";
        cout << a_w << " " << a_l << " " << d << "\n";
        cout << b_w << " " << b_l << " " << d << "\n";
        cout << "-------\n";
        
        if (a_w != b_l || a_l != b_w) {
            cout << "NO\n";
            continue;
        }

        if ((a_w + a_l + d) != n) {
            cout << "NO\n";
            continue;
        }

        vi a_cards;
        int i = n;
        for (int j = 0; j < a_w; ++j) {
            a_cards.PB(i);
            i--;
        }
        for (int j = 0; j < d; ++j) {
            a_cards.PB(i);
            i--;
        }
        for (int j = 0; j < a_l; ++j) {
            a_cards.PB(i);
            i--;
        }

        for (auto z : a_cards) {
            cout << z << " ";
        }
        cout << "\n";
    }

    return 0;
}