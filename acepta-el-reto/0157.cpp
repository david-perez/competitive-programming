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

int dateToInt(int d, int m, int y) {
    return
        1461*(y+4800+(m-14)/12)/4+
        367*(m-2-(m-14)/12*12)/12-
        3*((y+4900+(m-14)/12)/100)/4+
        d-32075;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int d, m; cin >> d >> m;
        cout << dateToInt(31, 12, 1) - dateToInt(d, m, 1) << endl;
    }

    return 0;
}