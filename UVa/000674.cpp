#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
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

int c[] = {50, 25, 10, 5, 1};
int memo[7490][6];

int num_ways(int qty, int i) {
    if (qty == 0) return 1;
    if (i == 5) return 0;

    if (memo[qty][i] != -1) return memo[qty][i];

    if (qty - c[i] >= 0)
        return memo[qty][i] = num_ways(qty - c[i], i) + num_ways(qty, i+1);
    return memo[qty][i] = num_ways(qty, i+1);
}

int main() {
    memset(memo, -1, sizeof memo);

    int qty;
    while (cin >> qty)
        cout << num_ways(qty, 0) << endl;

    return 0;
}