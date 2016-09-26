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
    int m, n, t;
    for (int t = 1; cin >> m >> n && !(m == 0 && n == 0); t++) {
        printf("Region %d\n", t);

        vd h;
        for (int i = 0; i < n*m; i++) {
            double x;
            cin >> x;
            h.push_back(x);
        }

        double V;
        cin >> V;
        V /= 100;

        sort(h.begin(), h.end());

        int i = 1; // number of tiles that are flush with the lowest-level tile
        int s = 0; // number of tiles that are submerged
        double ch = h[0]; // current height
        while (i < h.size() && V > 0) {
            double diff = (h[i] - ch) * i;
            if (V > diff) {
                V -= diff;
                ch = h[i];
                if (diff > 0) s = i;
                i++;
            } else {
                ch += (V / i);
                s = i;
                V = 0;
                break;
            }
        }

        if (V > 0) { // every tile will be submerged
            ch += (V / i);
            s = i;
        }

        printf("Water level is %.2f meters.\n", ch);
        printf("%.2f percent of the region is under water.\n\n", (double) s / h.size() * 100);
    }

    return 0;
}