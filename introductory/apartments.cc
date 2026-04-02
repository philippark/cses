#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sort(a) sort(a.begin(), a.end())

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vi applicants(n);
    vi apartments(m);

    for (auto&x : applicants) {
        cin >> x;
    }
    for (auto&x : apartments) {
        cin >> x;
    }

    sort(applicants);
    sort(apartments);

    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (abs(applicants[i] - apartments[j]) <= k) {
            ++count;
            ++i;
            ++j;
        } else {
            if (applicants[i] < apartments[j]) {
                ++i;
            } else {
                ++j;
            }
        }
    }

    cout << count << "\n";

    return 0;
}