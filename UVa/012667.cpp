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

int main() {
    int n, t, subs;
    cin >> n >> t >> subs;
    map<char, ii> m;
    bool solved[n][t];
    memset(solved, false, sizeof solved);
    while (subs--) {
        int time, id;
        string p;
        string v;
        cin >> time >> id >> p >> v;
        if (v == "Yes" && !solved[p[0] - 'A'][id-1]) {
            solved[p[0] - 'A'][id-1] = true;
            m[p[0]] = ii(time, id);
        }
    }

    for (char c = 'A'; c < 'A' + n; c++)
        if (m.count(c) > 0) printf("%c %d %d\n", c, m[c].first, m[c].second);
        else cout << c << " - -" << endl;

    return 0;
}