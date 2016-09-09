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

struct point {
    int x, y;

    point() : x(0), y(0) { }
    point(int _x, int _y) : x(_x), y(_y) { }
};

struct seg {
    point a, b;

    seg(point _a, point _b) : a(_a), b(_b) { }

    bool operator <(const seg &o) const {
        return !((max(a.y, b.y) < max(o.a.y, o.b.y))
            || (max(a.y, b.y) == max(o.a.y, o.b.y) && min(a.y, b.y) < min(o.a.y, o.b.y)));
    }
};

bool intersect(seg s, point p) {
    return min(s.a.x, s.b.x) <= p.x && p.x <= max(s.a.x, s.b.x) && p.y > min(s.a.y, s.b.y);
}

int fall(point p, vector<seg> &v) {
    for (seg &s: v)
        if (intersect(s, p))
            if (s.a.y < s.b.y) p = s.a;
            else p = s.b;

    return p.x;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<seg> v;
        int NP;
        cin >> NP;
        while (NP--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            v.push_back(seg(point(x1, y1), point(x2, y2)));
        }

        sort(v.begin(), v.end());

        int NS;
        cin >> NS;
        while (NS--) {
            int x, y;
            cin >> x >> y;
            cout << fall(point(x, y), v) << endl;
        }

        if (T > 0) cout << endl;
    }

    return 0;
}