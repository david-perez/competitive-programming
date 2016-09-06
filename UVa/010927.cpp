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
#include <tuple>

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
    ll x, y, z;

    point() : x(0), y(0), z(0) { }
    point(ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) { }

    bool operator ==(const point &o) const {
        return x * o.y == y * o.x;
    }

    bool operator <(const point &o) const {
        return (x * o.y < y * o.x)
            || ((*this == o) && x*x + y*y < o.x*o.x + o.y*o.y);
    }
};


int main() {
    int N;
    for (int t = 1; cin >> N && N != 0; t++) {
        vector<point> v;
        while (N--) {
            ll x, y, z;
            cin >> x >> y >> z;
            v.push_back(point(x, y, z));
        }

        sort(v.begin(), v.end());

        vii sol;
        int h = v[0].z;
        for (int i = 1; i < v.size(); i++)
            if (v[i] == v[i-1] && v[i].z <= h)
                sol.push_back(ii(v[i].x, v[i].y));
            else h = v[i].z;

        sort(sol.begin(), sol.end());

        printf("Data set %d:\n", t);
        if (sol.empty()) cout << "All the lights are visible." << endl;
        else {
            cout << "Some lights are not visible:" << endl;
            for (int i = 0; i < sol.size() - 1; i++)
                printf("x = %d, y = %d;\n", sol[i].first, sol[i].second);
            printf("x = %d, y = %d.\n", sol[sol.size() - 1].first, sol[sol.size() - 1].second);
        }
    }

    return 0;
}