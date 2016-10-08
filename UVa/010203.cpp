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
        int a, b;
        cin >> a >> b; // useless info
        cin.get();
        string s;
        double d = 0; // distance (in metres)
        while (getline(cin, s) && !s.empty()) {
            stringstream ss(s);
            int x0, y0, x1, y1;
            ss >> x0 >> y0 >> x1 >> y1;
            d += hypot(x1-x0, y1-y0);
        }

        d *= 2; // two lanes per road
        double h = d / 20000; // 20 km = 20000 m
        int hh = (int) h;
        int mm = round((h - hh) * 60);
        if (mm == 60) {
            hh++;
            mm = 0;
        }
        printf("%d:%02d\n", hh, mm);

        if (T > 0) cout << endl;
    }

    return 0;
}