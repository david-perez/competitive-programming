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
    int T, a, b, c, k;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> a >> b >> c;
        if ((a <= b && b <= c) || (c <= b && b <= a)) k = b;
        else if (a <= c && c <= b || (b <= c && c <= a)) k = c;
        else k = a;
        printf("Case %d: %d\n", i, k);
    }
    
    return 0;
}
