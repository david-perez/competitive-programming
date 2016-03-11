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
    int T;
    cin >> T;
    while (T--) {
        int D; cin >> D;
        vector<string> makers; vii prices;
        while (D--) {
            string m; int l, h;
            cin >> m >> l >> h;
            makers.push_back(m);
            prices.push_back(ii(l, h));
        }

        int Q; cin >> Q;
        while (Q--) {
            int p; cin >> p;
            int matches = 0; string maker = "";
            for (int i = 0; i < makers.size(); i++) {
                if (prices[i].first <= p && p <= prices[i].second) {
                    maker = makers[i];
                    matches++;
                    if (matches > 1) break;
                }
            }

            if (matches > 1 || matches == 0) cout << "UNDETERMINED" << endl;
            else cout << maker << endl;
        }
        if (T > 0) cout << endl;
    }

    return 0;
}