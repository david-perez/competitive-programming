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

struct cmp {
    bool operator() (const ii &a, const ii &b) {
        return a.first < b.first ||
               (a.first == b.first && a.second > b.second);
    }
};

int main() {
    int L, G;
    while (cin >> L >> G && !(L == 0 && G == 0)) {
        vii v;
        while (G--) {
            int x, r;
            cin >> x >> r;
            v.push_back(ii(x-r, x+r));
        }

        sort(v.begin(), v.end(), cmp());

        vii sol;
        int i = 0;
        ii p = ii(0, 0);
        while (i < v.size() && p.second < L) {
            ii q = v[i];

            if (q.first > p.second)
                break;

            while (i < v.size() && v[i].first <= p.second) {
                if (v[i].second > q.second)
                    q = v[i];

                i++;
            }

            sol.push_back(q);
            p = q;
        }

        if (sol.size() > 0 && sol[sol.size() - 1].second >= L)
            cout << v.size() - sol.size() << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}