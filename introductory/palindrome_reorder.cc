/*
Idea:
In order to be a possible palindrome,
all but one character must have equal frequencies.

We can just create the palindrome by splitting,
and if there is one char with odd frequencies,
that must be put in the middle.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> v(26, 0);
    for (auto c : s) {
        v[c-'A']++;
    }

    std::string left="", mid="", right="";
    char ch = 'A';
    for (auto i : v) {
        if (i%2 != 0) {
            if (mid != "") {
                cout << "NO SOLUTION\n";
                return 0;
            }
            mid = string(i, ch);
        } else {
            left += string(i/2, ch);
            right += string(i/2, ch);
        }
        ch += 1;
    }
    reverse(right.begin(), right.end());
    cout << left + mid + right << "\n";

    return 0;
}