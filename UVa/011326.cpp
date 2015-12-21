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

const long double pi = acos(-1.0);

int main() {
    int t, L, W, th, N;
    double d, lm, u, A, B;
    cin >> t;
    while (t--) {
        cin >> L >> W >> th;
        
        d = W/tan(th*pi/180);
        N = floor(L/d);
        lm = L-N*d;
        A = floor(L/d) * W/sin(th*pi/180) + lm/cos(th*pi/180);
        u = lm*tan(th*pi/180);
        if (N % 2 != 0) u = W - u;
        B = sqrt(L*L + u*u);
        
        printf("%.3f\n", th == 0 ? 1 : A/B);
    }
    
    return 0;
}