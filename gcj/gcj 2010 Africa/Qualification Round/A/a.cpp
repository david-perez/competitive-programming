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
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);

    int N;
    cin >> N;
    for (int t = 1; t <= N; t++) {
        int C; cin >> C;
        int l; cin >> l;
        vi prices;
        while (l--) {
            int P; cin >> P;
            prices.push_back(P);
        }
        int i = 0, j = 0;
        while (i < prices.size()) {
            j = i + 1;
            while (j < prices.size()) {
                if (prices[i] + prices[j] == C) goto done;
                j++;
            }
            i++;
        }
        done:
            printf("Case #%d: %d %d\n", t, i+1, j+1);
    }

    return 0;
}