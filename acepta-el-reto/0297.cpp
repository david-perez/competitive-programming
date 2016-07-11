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

int main() {
    map<string, int> m;
    m["o"] = 1;
    m["da"] = 10;
    m["h"] = 100;
    m["k"] = 1000;
    m["M"] = 1000000;
    m["G"] = 1000000000;

    int T;
    cin >> T;
    while (T--) {
        int o = 0;
        int x;
        while (cin >> x && x != 0) {
            string u;
            cin >> u;
            o += x * m[u];
        }

        if ((o / m["G"]) * m["G"] == o) printf("%d %s\n", o / m["G"], "G");
        else if ((o / m["M"]) * m["M"] == o) printf("%d %s\n", o / m["M"], "M");
        else if ((o / m["k"]) * m["k"] == o) printf("%d %s\n", o / m["k"], "k");
        else if ((o / m["h"]) * m["h"] == o) printf("%d %s\n", o / m["h"], "h");
        else if ((o / m["da"]) * m["da"] == o) printf("%d %s\n", o / m["da"], "da");
        else printf("%d %s\n", o, "o");
    }

    return 0;
}