#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

struct teamqueue {
    vector<bool> inq;
    vector<queue<int>> v;
    queue<int> q;

    teamqueue(int t) {
        inq.assign(t, false);
        v.assign(t, queue<int>());
        q = queue<int>();
    }

    int dequeue() {
        int team = q.front(), x = v[team].front(); v[team].pop();

        if (v[team].empty()) {
            q.pop();
            inq[team] = false;
        }

        return x;
    }

    void enqueue(int team, int x) {
        if (!inq[team]) {
            q.push(team);
            inq[team] = true;
        }

        v[team].push(x);
    }
};

int main() {
    int t;
    for (int k = 1; cin >> t && t != 0; k++) {
        map<int, int> xtt;
        for (int i = 0; i < t; i++) {
            int n;
            cin >> n;
            while (n--) {
                int x;
                cin >> x;
                xtt[x] = i;
            }
        }

        printf("Scenario #%d\n", k);
        teamqueue tq(t);
        string s;
        getline(cin, s);
        while (getline(cin, s) && s != "STOP") {
            if (s == "DEQUEUE") cout << tq.dequeue() << endl;
            else {
                stringstream ss(s);
                ss >> s;
                int x;
                ss >> x;
                tq.enqueue(xtt[x], x);
            }
        }

        cout << endl;
    }

    return 0;
}
