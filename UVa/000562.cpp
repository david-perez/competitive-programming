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
typedef vector<id> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

bitset<25001> vis;

int main() {
    int n;
    cin >> n;
    while (n--) {
        vis.reset(); vis[0] = 1;
        int m;
        cin >> m;

        int sum = 0;
        vi coins;
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c; coins.push_back(c);
            sum += c;
        }

        while (m--) {
            int c = coins[m];
            for (int i = sum/2; i >= c; i--) {
                if (vis[i] == 0)
                    vis[i] = vis[i-c];
            }
        }

        int i = sum/2;
        while (i >= 0) {
            if (vis[i] == 1) break;
            i--;
        }
        cout << sum - 2*i << endl;
    }

    return 0;
}