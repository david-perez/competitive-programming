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
    int numSets;
    vi p, r;
    
    ufds(int N) {
        numSets = N;
        p.assign(N, 0); r.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    
    int find(int i) {
        return p[i] == i ? i : find(p[i]);
    }
    
    void unionSet(int i, int j) {
        int x = find(i), y = find(j);
        if (x != y) {
            if (r[x] > r[y]) p[y] = x;
            else {
                p[x] = y;
                if (r[x] == r[y]) r[y]++;
            }
            numSets--;
        }
    }
};

int main() {
    int t;
    
    scanf("%d\n\n", &t);
    
    char u, v; char s[5];
    while (t--) {
        u = cin.get(); cin.get();
        ufds graph(u - 'A' + 1);
        
        while (gets(s) && strcmp(s, "") != 0) {
            sscanf(s, "%c%c", &u, &v);
            graph.unionSet(u - 'A' + 1, v - 'A' + 1);
        }
        
        // unique representatives of ufds is number of connected components
        cout << graph.numSets << endl;
        if (t) cout << endl; // blank line between input sets
    }

    return 0;
}