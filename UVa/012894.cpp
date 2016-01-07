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
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x0, y0, x1, y1, cx, cy, r;
        cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;
 
        int l = x1 - x0;
        int w = y1 - y0;
 
        if ((10*w == 6*l) && (5*r == l) && 2*(cy-y0) == w && 20*(cx-x0) == 9*l) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
