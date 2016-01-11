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
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
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

int main() {
    int e, V, u, v;
    vi deg;
    
    while (scanf("%d %d", &V, &e) == 2) {
        deg.assign(V, 0);
        ufds uf(V);
        
        for (int i = 0; i < e; i++) {
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
            uf.unionSet(u, v);
        }
        
        int p = -1;
        for (int i = 0; i < V; i++)
            if (deg[i] > 0)
                p = uf.findSet(i);
        
        bool eul = true;
        for (int i = 0; i < V; i++) {
            if (deg[i] % 2 == 1 || (p != -1 && deg[i] > 0 && !uf.isSameSet(p, i))) {
                eul = false;
                break;
            }
        }
        
        if (e == 0) { // the judge treats this special case differently!
            cout << "Not Possible" << endl;
            continue;
        }
        cout << (eul ? "Possible" : "Not Possible") << endl;
    }
    
    return 0;
}