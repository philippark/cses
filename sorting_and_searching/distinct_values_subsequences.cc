/*
Given a frequency of duplicates,
we have freq+1 choices to choose from those.
choose f1, choose f2, .... choose none of them.
multiply that by the amount of choices in the past. to combine with.

in the end, there is one element that is a result of choosing nothing all along.
remove that.

buffet analogy:
3 apples
2 bananas

can choose one of either bucket.
can choose 1st apple, 2nd apple, 3rd apple, or no apples. 4 choices for apples.
can choose 1st banana, 2nd banana, or no bananas. 3 choices for bananas.

total number of combinations: 4*3 = 12. 
but there is a combo that is choosing no apple and choosing no banana.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;

#define PB push_back
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define M 1000000007
#define INF 2147483647
#define INFL 9223372036854775807
#define MOD 998244353

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(auto&x : arr){
        cin>>x;
    }
    sort(arr, arr+n);

    ll res = 1;
    int freq = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i-1]) {
            res = res * (freq+1) % M;
            freq = 0;
        }
        ++freq;
    }

    res = res * (freq+1) % M;
    cout << res-1 << "\n";

    return 0;
}