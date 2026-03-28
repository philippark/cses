'''
Idea:
Greedy solution. 
try to choose the lexicographically smallest character that
    1) isn't the same as last chosen char
    2) doesn't cause the rest of the chars to be impossible to resolve

for 2):
    given the frequency of a char, it needs at-least freq-1 other chars to satisfy itself

O(n*26*26)
'''

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    vi freqs(26, 0);

    for (int i = 0; i < n; ++i) {
        freqs[s[i]-'A']++;
    }

    string ans = "";
    while (n--) {
        bool stuck = true;
        // find lexicographically smallest char to add
        for (int i = 0; i < 26; ++i) {
            char c = char('A' + i);
            if (freqs[i]==0 || c == ans[ans.size()-1]) {
                continue;
            }
            freqs[i]--;

            // check if it doesn't cause the rest to be impossible
            bool bad = false;
            for (int j = 0; j < 26; ++j) {
                if (j == i || freqs[j]==0) {
                    continue;
                }
                int needs = freqs[j]-1;
                // check if this char has enough to satisfy itself as well
                if (((n-1)-(freqs[j]-1)) < needs) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                freqs[i]++;
                continue;
            } else {
                stuck = false;
                ans += c;
                break;
            }
        }

        if (stuck) {
            cout << -1;
            return 0;
        }
    }

    cout << ans << "\n";

    return 0;
}