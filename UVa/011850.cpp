#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
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
    int n;
    while (cin >> n && n != 0)  {
        vi v;
        while (n--) {
            int x; cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        if (1422 - v[v.size() - 1] > 100)  {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        bool possible = true;
        int a = 0;
        for (int x : v) {
            if (x - a > 200) {
                possible = false;
                break;
            }
            a = x;
        }

        cout << (possible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }

    return 0;
}