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
    int T;
    cin >> T;
    while (T--) {
        int M;
        cin >> M;

        vii v;
        int l, r;
        while (cin >> l >> r && !(l == 0 && r == 0))
            v.push_back(ii(l, r));

        sort(v.begin(), v.end(), cmp());

        int i = 0;
        while (i < v.size() && v[i].second < 0) i++;

        vii sol;
        ii p = ii(0, 0);
        while (i < v.size() && p.second < M) {
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

        if (sol.size() > 0 && sol[sol.size() - 1].second >= M) {
            cout << sol.size() << endl;
            for (auto &p : sol)
                printf("%d %d\n", p.first, p.second);
        } else
            cout << 0 << endl;

        if (T > 0) cout << endl;
    }

    return 0;
}