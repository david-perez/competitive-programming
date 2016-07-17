#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <list>
#include <forward_list>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

#define INF 1000000000 // 10^9

int adjMat[100][100];
int pi[100][100];
int N;

void floyd() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    pi[i][j] = pi[k][j];
                }
}

void path(int i, int j, map<int, string> &v2c, vector<string> &p) {
    if (i != j) path(i, pi[i][j], v2c, p);
    p.push_back(v2c[j]);
}

int main() {
    map<string, int> c2v; // city to vertex
    map<int, string> v2c; // vertex to city
    map<ii, pair<string, int>> e2h; // edge (vertex, vertex) to (highway, weight)

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (i == j) adjMat[i][i] = 0;
            else adjMat[i][j] = INF, pi[i][j] = i;

    N = 0; // vertex number

    string s;
    while (getline(cin, s) && s.length() > 0) {
        stringstream ss(s);
        string c1, c2, r;
        int u, v, w;

        getline(ss, c1, ',');
        getline(ss, c2, ',');
        getline(ss, r, ',');
        ss >> w;

        if (c2v.count(c1) == 0) {
            c2v[c1] = N;
            v2c[N] = c1;
            N++;
        }

        if (c2v.count(c2) == 0) {
            c2v[c2] = N;
            v2c[N] = c2;
            N++;
        }

        u = c2v[c1];
        v = c2v[c2];

        if (w < adjMat[u][v]) { // There can be more than one road between two cities; we want the one with minimum weight
            e2h[ii(u, v)] = make_pair(r, w);
            e2h[ii(v, u)] = make_pair(r, w);

            adjMat[u][v] = w;
            adjMat[v][u] = w;
        }
    }

    floyd();

    while (getline(cin, s) && s.length() > 0) {
        stringstream ss(s);
        string c1, c2;
        getline(ss, c1, ',');
        getline(ss, c2, ',');

        int u = c2v[c1];
        int v = c2v[c2];

        cout << endl << endl;
        cout << "From                 To                   Route      Miles" << endl;
        cout << "-------------------- -------------------- ---------- -----" << endl;

        vector<string> p;
        path(u, v, v2c, p);

        for (int i = 0; i < p.size() - 1; i++) {
            printf("%-21s", p[i].c_str());
            printf("%-21s", p[i+1].c_str());
            auto highway = e2h[ii(c2v[p[i]], c2v[p[i+1]])];
            printf("%-11s", highway.first.c_str());
            printf("%5d", highway.second);
            cout << endl;
        }

        cout << "                                                     -----" << endl;
        cout << "                                          Total      ";
        printf("%5d\n", adjMat[u][v]);
    }

    return 0;
}