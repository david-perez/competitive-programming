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

struct turtle {
    int w;
    int s;

    const bool operator <(const turtle &t2) {
        return s < t2.s;
    }
};

int main() {
    int dp[5607]; // dp[k] is the minimum weight of a stack of turtles of height k
    fill(dp, dp + 5607, INT_MAX);
    dp[0] = 0;
    vector<turtle> v;

    turtle t;
    while (cin >> t.w >> t.s)
        v.push_back(t);

    // We consider first weaker turtles: in case of the existence of two different stacks of same height and
    // same minimum weight, the weaker stack is "built" first so that the stronger turtles can be put underneath it.
    sort(v.begin(), v.end());

    int maxH = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = maxH; j >= 0; j--)
            if (v[i].s >= dp[j] + v[i].w && v[i].w + dp[j] < dp[j+1]) {
                dp[j+1] = dp[j] + v[i].w;
                maxH = max(maxH, j+1);
            }

    cout << maxH << endl;

    return 0;
}