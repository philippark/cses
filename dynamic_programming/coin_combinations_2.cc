/*
Idea:
1 pass per coin,
go through the coins in sorted order and count the ways
you can arrive at a certain sum with the specific coin.
this way, it's guaranteed you are adding to a pile of 
previous coins <= current coin.
*/

#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

const int N = 1e6+5;
int change[N];

int main() {
    int n,x;
    cin>>n>>x;
    int coins[n];
    for(auto&x:coins)cin>>x;
    change[0] = 1;
    for (auto coin : coins) {
        for (int i = 1; i <= x; ++i) {
            if (i-coin >= 0){
                change[i] += change[i-coin];
                change[i]%=M;
            }
        }
    }

    cout << change[x];

    return 0;
}