/*
Idea:
strip the tree leaf by leaf and then multiply by 2 once it ends
one edge case to keep in mind is that if it boils down to 
just 2 nodes connected to each other, that one edge must be counted as +1.
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define PB push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, vi> edges;
    unordered_map<int, int> edge_count;

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;

        edges[a].PB(b);
        edges[b].PB(a);
        ++edge_count[a];
        ++edge_count[b];
    }

    queue<int> q;
    for (auto p : edge_count) {
        if (p.second == 1) {
            q.push(p.first);
        }
    }

    int count = 0;
    while (n > 2) { 
        int size = q.size();
        n -= size;
        for (int i = 0; i < size; ++i) {
            int x = q.front();
            q.pop();

            --edge_count[x];

            for (auto y : edges[x]) {
                --edge_count[y];
                if (edge_count[y] == 1) {
                    q.push(y);
                }
            }
        }
        ++count;
    }

    cout << 2*count + (n==2 ? 1 : 0);
    return 0;
}