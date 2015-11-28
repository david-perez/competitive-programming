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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

struct ufds {
    vi p, r;
    int numSets;
    
    ufds(int N) {
        p.assign(N, 0); r.assign(N, 0); numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }
    
    int findSet(int i) { // finds and path compresses if possible
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (r[x] > r[y]) p[y] = x;
            else {
                p[x] = y;
                if (r[x] == r[y]) r[y]++;
            }
            numSets--;
        }
    }
    
    void print() {
        cout << "p[] = ";
        for (int i = 0; i < p.size(); i++)
            cout << i << " -> " << p[i] << "; ";
        cout << endl;
    }
};

// edgeList will get sorted
int kruskal(const int &V, const int &E, vector<pair<int, ii> > &edgeList) {
    sort(edgeList.begin(), edgeList.end());
    int mst_cost = 0;
    ufds uf(V);
    
    for (int i = 0; i < E && uf.numSets != 1; i++) {
        pair<int, ii> front = edgeList[i];
        if (uf.findSet(front.second.first) != uf.findSet(front.second.second)) {
            mst_cost += front.first;
            uf.unionSet(front.second.first, front.second.second);
        }
    }
    
    return mst_cost;
}

int main() {
    int n, k, m, u, v, w, orig_cost;
    
    vector<pair<int, ii> > edgeList;
    
    bool newline = false;
    
    while (cin >> n) {
        if (newline) cout << endl;
        
        orig_cost = 0;
        for (int i = 0; i < n-1; i++) {
            cin >> u >> v >> w;
            orig_cost += w;
        }
        
        edgeList.clear();
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> w;
            edgeList.push_back(make_pair(w, ii(u-1, v-1)));
        }
        
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edgeList.push_back(make_pair(w, ii(u-1, v-1)));
        }
        
        cout << orig_cost << endl;
        cout << kruskal(n, m+k, edgeList) << endl;
        newline = true;
    }

    return 0;
}