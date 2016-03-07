#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
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

int coinValue[5] = {1, 5, 10, 25, 50};
ll memo[5][30001]; // yes, the judge tests the case where n = 30000

ll ways(int id, int value) {
    if (value == 0) return 1;
    if (id == 5 || value < 0) return 0;
    if (memo[id][value] != -1)
        return memo[id][value];

    return memo[id][value] = ways(id+1, value) + ways(id, value-coinValue[id]);
}

int main() {
    memset(memo, -1, sizeof memo);

    int n;
    while (cin >> n) {
        ll m = ways(0, n);
        printf("There %s %lld %s to produce %d cents change.\n", m == 1 ? "is only" : "are", m, m == 1 ? "way" : "ways", n);
    }

    return 0;
}