/*
Idea:
the number of subsequences only gets impacted if for a number n,
it's relative positioning with n-1 and n+1 changes
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int arr[n+3];
    int pos[n+3];

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    pos[0] = n+1;
    pos[n+1] = n+2;

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (pos[i] < pos[i-1]) count++;
    }

    while (q--) {
        int a, b, x, y;
        cin >> a >> b;
        x = arr[a];
        y = arr[b];
        
        if (pos[x] < pos[x-1]) count--;
        if ((pos[x+1] < pos[x]) && (x+1!=y)) count--;

        if (pos[y] < pos[y-1]) count--;
        if ((pos[y+1] < pos[y]) && (y+1!=x)) count--;

        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);
        swap(x, y);
   
        if (pos[x] < pos[x-1]) count++;
        if ((pos[x+1] < pos[x]) && (x+1!=y)) count++;

        if (pos[y] < pos[y-1]) count++;
        if ((pos[y+1] < pos[y]) && (y+1!=x)) count++;

        cout << count << "\n";
    }

    return 0;
}