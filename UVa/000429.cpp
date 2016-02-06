#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
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
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<pair<int, double>> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

bool differ(string s, string t) { // returns true if they differ by one letter
    if (s.size() != t.size()) return false;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != t[i]) cnt++;
    return cnt == 1;
}

int bfs(int s, int d, vvi &adjList) {
    vi dist; dist.assign(adjList.size(), INT_MAX);
    dist[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                if (v == d) return dist[d];
                q.push(v);
            }
        }
    }
}

int main() {
    int N;
    
    scanf("%d\n\n", &N);
    while (N--) {
        string s;
        vector<string> dict;
        vvi adjList;
        
        for (int j = 0; getline(cin, s) && s!= "*"; j++) {
            dict.push_back(s);
            adjList.push_back(vi());
            for (int i = 0; i < adjList.size()-1; i++)
                if (differ(dict[i], s)) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
        }
        
        string t;
        while (getline(cin, s) && s != "") {
            stringstream ss(s);
            ss >> s >> t;
            int i = find(dict.begin(), dict.end(), s) - dict.begin();
            int j = find(dict.begin(), dict.end(), t) - dict.begin();
            printf("%s %s %d\n", s.c_str(), t.c_str(), bfs(i, j, adjList));
        }
        if (N > 0) cout << endl;
    }
    
    return 0;
}
