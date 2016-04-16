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
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        vi h, d;
        while (n--) {
            int di; cin >> di;
            d.push_back(di);
        }
        while (m--) {
            int hi; cin >> hi;
            h.push_back(hi);
        }
        sort(h.begin(), h.end());
        sort(d.begin(), d.end());
        int i = 0, j = 0, coins = 0;
        while (i < h.size() && j < d.size()) {
            if (h[i] >= d[j]) coins += h[i], i++, j++;
            else i++;
        }
        if (j == d.size()) cout << coins << endl;
        else cout << "Loowater is doomed!" << endl;
    }

    return 0;
}