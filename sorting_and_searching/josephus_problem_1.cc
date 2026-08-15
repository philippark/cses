/*
Idea:
I just used a simple linkedlist simulation. 
*/

#include <bits/stdc++.h>
using namespace std;

#define PB push_back

int main() {
    int n;
    cin>>n;

    list<int> arr;
    for (int i=1; i<=n; ++i) {
        arr.PB(i);
    }
    
    int start = 1;
    while (arr.begin() != arr.end()) {
        auto it = arr.begin();
        if (start) ++it;
        if (it == arr.end()) {
            it = arr.begin();
            cout << *it << "\n";
            it = arr.erase(it);
            continue;
        }

        while (it != arr.end()) {
            cout << *it << "\n";
            it = arr.erase(it);
             if (it == arr.end()) {
                start = 1;
                break;
            }
            ++it;
            start = 0;
        }
    }

    return 0;
}