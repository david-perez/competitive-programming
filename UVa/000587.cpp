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
    map<string, pair<double, double>> m;
    double a = 1.0 / sqrt(2);
    m["N"] = make_pair(0, 1);
    m["E"] = make_pair(1, 0);
    m["S"] = make_pair(0, -1);
    m["W"] = make_pair(-1, 0);
    m["NE"] = make_pair(a, a);
    m["SE"] = make_pair(a, -a);
    m["SW"] = make_pair(-a, -a);
    m["NW"] = make_pair(-a, a);

    string s;
    for (int t = 1; getline(cin, s) && s != "END"; t++) {
        double x = 0, y = 0;
        s = s.substr(0, s.length() - 1);
        stringstream ss(s);
        string cm;
        while (getline(ss, cm, ',')) {
            stringstream st(cm);
            int mult;
            string c;
            st >> mult >> c;
            x += mult * m[c].first;
            y += mult * m[c].second;
        }

        printf("Map #%d\n", t);
        printf("The treasure is located at (%.3f,%.3f).\n", x, y);
        printf("The distance to the treasure is %.3f.\n\n", hypot(x, y));
    }

    return 0;
}