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

set<int> h; // happy numbers
set<int> unh; // unhappy numbers

int happy(int n) {
    int s = 0;
    while (n > 0) {
        s += (n % 10) * (n % 10);
        n /= 10;
    }

    return s;
}

bool isHappy(int n) {
    if (n == 1 || h.count(n) > 0) return true;
    if (n == 4 || unh.count(n) > 0) return false;

    if (isHappy(happy(n))) {
        h.insert(n);
        return true;
    } else {
        unh.insert(n);
        return false;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        printf("Case #%d: %d is %s number.\n", t, n, isHappy(n) ? "a Happy" : "an Unhappy");
    }

    return 0;
}