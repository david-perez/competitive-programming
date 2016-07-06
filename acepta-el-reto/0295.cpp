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

int k = 31543;

int pow(int x, int n) {
    if (n == 0) return 1;

    if (n % 2 == 0) {
        int x1 = pow(x, n/2);
        return (x1 * x1) % k;
    } else {
        int x1 = pow(x, (n-1)/2);
        return (((x1 * x1) % k) * (x % k)) % k;
    }
}

int main() {
    int x, n;
    while (cin >> x >> n && !(x == 0 && n == 0)) {
        cout << pow(x, n) << endl;
    }

    return 0;
}