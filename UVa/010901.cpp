#include <iostream>
#include <queue>

using namespace std;

queue<int> Q[2];

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, t, m;
        cin >> n >> t >> m;
        int arrive[m], leave[m];
        for (int i = 0; i < m; i++) {
            int minute;
            string side;
            cin >> minute >> side;
            arrive[i] = minute;
            if (side == "left") Q[0].push(i);
            else Q[1].push(i);
        }

        int time = 0, side = 0;
        while (!(Q[0].empty() && Q[1].empty())) {
            int next = Q[0].empty() ? arrive[Q[1].front()] :
                       Q[1].empty() ? arrive[Q[0].front()] :
                       min(arrive[Q[0].front()], arrive[Q[1].front()]);
            time = max(time, next);
            int cnt = 0;
            while (!Q[side].empty() && arrive[Q[side].front()] <= time && cnt < n) {
                leave[Q[side].front()] = time + t;
                cnt++;
                Q[side].pop();
            }
            time += t;
            side = 1 - side;
        }

        for (int tl : leave) cout << tl << endl;
        
        if (c > 0) cout << endl;
    }
}
