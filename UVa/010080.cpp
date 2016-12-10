#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

int n, m;
vvi adjList;
vi vis, match;

double dist(dd &p, dd &q) {
    double dy = q.second - p.second;
    double dx = q.first - p.first;
    return sqrt(dx*dx + dy*dy);
}

int aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < adjList[l].size(); j++) {
        int r = adjList[l][j];
        if (match[r] == -1 || aug(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int berge_mcbm() {
    int mcbm = 0;
    match.assign(n+m, -1);
    vis.assign(n, 0);
    for (int l = 0; l < n; l++) {
        vis.assign(n, 0);
        mcbm += aug(l);
    }

    return mcbm;
}

int main() {
    int s, v;
    while (cin >> n >> m >> s >> v) {
        vdd gophers;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            gophers.push_back(dd(x, y));
        }

        adjList.assign(n, vi());
        for (int j = 0; j < m; j++) {
            double x, y;
            cin >> x >> y;
            dd hole = dd(x, y);
            for (int i = 0; i < n; i++)
                if (dist(gophers[i], hole) <= v*s)
                    adjList[i].push_back(j);
        }

        int mcbm = berge_mcbm();
        cout << n - mcbm << endl;
    }

    return 0;
}