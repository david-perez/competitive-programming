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
#define PI acos(-1)
#define EPS 1e-9

vii edgeList;
int n, m;
int s; // selected junctions
int bs; // min cover junctions
int used; // # selected junctions
int best; // # min cover junctions

void backtrack(int k = 0) {
    if (used > best) return;

    if (k == m) {
        if (used < best) {
            bs = s;
            best = used;
        }
        return;
    }

    ii e = edgeList[k];
    int u1 = e.first;
    int u2 = e.second;

    if ((s & (1 << u1)) || (s & (1 << u2)))
        backtrack(k + 1);
    else {
        s |= (1 << u1), used++;
        backtrack(k+1);
        s &= ~(1 << u1), used--;

        s |= (1 << u2), used++;
        backtrack(k+1);
        s &= ~(1 << u2), used--;
    }
}

int main() {
    int N;
    cin >> N;
    for (int t = 1; t <= N; t++) {
        cin >> n >> m;
        edgeList.clear();

        for (int i = 0; i < m; i++) {
            int s, t;
            cin >> s >> t;
            edgeList.push_back(ii(s, t));
        }

        bs = 0;
        s = 0;
        best = n;
        for (int i = 0; i < 30; i++) // 0 -> not selected, 1 -> selected
            if (i < n) bs |= (1 << i); // Select all junctions as best initial solution

        backtrack();

        printf("Case #%d: %d\n", t, best);
        for (int i = 0; i < n; i++)
            if ((1 << i) & bs) cout << i << ' ';
        cout << endl;
    }

    return 0;
}