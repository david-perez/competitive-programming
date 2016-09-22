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
    int v[100001];
    v[0] = 0;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        sort(v, v + n);

        int lo = 0, hi = 10000000, mi; // hi = 10^7
        while (lo < hi) {
            mi = (lo + hi) / 2;
            bool ok = true;
            for (int i = 0, k = mi; i < n && ok; i++) {
                if (v[i+1] - v[i] > k) ok = false;
                else if (v[i+1] - v[i] == k) k--;
            }

            if (!ok) lo = mi + 1;
            else hi = mi;
        }

        printf("Case %d: %d\n", t, lo);
    }

    return 0;
}