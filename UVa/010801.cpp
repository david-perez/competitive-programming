#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> ii;

int n, k, b[101][5], dist[101][5], T[5];

struct state {
    int d, f, e;

    bool operator <(const state &o) const {
        return d < o.d;
    }

    ii up() {
        for (int i = f+1; i < 101; i++)
            if (b[i][e] == 1) return ii(i, e);
        return ii(-1, -1);
    }

    ii down() {
        for (int i = f-1; i >= 0; i--)
            if (b[i][e] == 1) return ii(i, e);
        return ii(-1, -1);
    }
};

int dijkstra() {
    priority_queue<state, vector<state>> pq;
    for (int e = 0; e < n; e++)
        if (b[0][e] == 1) {
            dist[0][e] = 0;
            pq.push({0, 0, e});
        }

    while (!pq.empty()) {
        state front = pq.top(); pq.pop();
        int d = front.d, f = front.f, e = front.e;
        if (d > dist[f][e]) continue;

        ii up = front.up();
        if (up != ii(-1, -1) && d + (up.first - f)*T[e] < dist[up.first][up.second]) {
            dist[up.first][up.second] = d + (up.first - f)*T[e];
            pq.push({dist[up.first][up.second], up.first, up.second});
        }

        ii down = front.down();
        if (down != ii(-1, -1) && d + (f - down.first)*T[e] < dist[down.first][down.second]) {
            dist[down.first][down.second] = d + (f - down.first)*T[e];
            pq.push({dist[down.first][down.second], down.first, down.second});
        }

        for (int j = 0; j < n; j++)
            if (j != e && b[f][j] == 1 && d + 60 < dist[f][j]) {
                dist[f][j] = d + 60;
                pq.push({dist[f][j], f, j});
            }
    }

    int sol = INT_MAX;
    for (int e = 0; e < n; e++) sol = min(sol, dist[k][e]);
    return sol;
}

int main() {
    while (cin >> n >> k) {
        for (int f = 0; f < 101; f++)
            for (int e = 0; e < n; e++)
                b[f][e] = 0, dist[f][e] = INT_MAX;

        for (int e = 0; e < n; e++) cin >> T[e];
        cin.get();
        for (int e = 0; e < n; e++) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int f;
            while (ss >> f) b[f][e] = 1;
        }

        int d = dijkstra();
        if (d == INT_MAX) cout << "IMPOSSIBLE" << endl;
        else cout << d << endl;
    }

    return 0;
}
