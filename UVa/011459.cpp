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
    int T;
    cin >> T;
    while (T--) {
        map<int, int> m;

        int a, b, c;
        cin >> a >> b >> c;
        while (b--) {
            int u, v;
            cin >> u >> v;
            m[u] = v;
        }

        vi pos(a, 1); // a players at pos 1
        bool won = false;
        for (int i = 0; c > 0; c--, i = (i+1) % a) {
            int x;
            cin >> x;

            if (!won) {
                pos[i] = min(pos[i] + x, 100);
                if (m.count(pos[i]) > 0)
                    pos[i] = m[pos[i]];
                won = (pos[i] == 100);
            }
        }

        for (int i = 0; i < a; i++)
            printf("Position of player %d is %d.\n", i+1, pos[i]);
    }

    return 0;
}