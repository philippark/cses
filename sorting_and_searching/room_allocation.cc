/*
Idea:
pretend you are the frontdesk of a hotel.
you just need to handle each client as they come.
if they are an arriving client, give them any available room.
if they are departing, mark the room they used as free now. 

we can simulate this behavior through a pq, 
we just need to give a higher priority to arrivers so
that they can treated first. this handles the edge case of 
departers on the same date as arrivers. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define PB push_back

int main() {
    int n;
    cin >> n;
    priority_queue<vi, vvi, greater<vi>> pq;

    vvi entries(n, vi(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> entries[i][0] >> entries[i][1];
        pq.push({entries[i][0], 0, i});
    }

    int res[n];
    vi rooms;
    int last_given = 0;

    while (!pq.empty()) {
        vi v = pq.top();
        pq.pop();

        if (v[1]) { // customer that departed
            int room = v[2];
            rooms.PB(room);
        } else { // customer that arrived
            int idx = v[2];
            int departure = entries[idx][1];
            
            int room = last_given+1;
            if (rooms.empty()) {
                ++last_given;
            } else {
                room = rooms.back();
                rooms.pop_back();
            }

            pq.push({departure, 1, room});
            res[idx] = room;
        }
    }

    cout << last_given << "\n";
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}