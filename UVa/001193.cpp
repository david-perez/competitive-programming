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
    int n, d, x, y, t = 1;
    double s1, s2;
    while (scanf("%d %d", &n, &d) && n != 0 && d != 0) {
        int radars = 0;
        vdd intervals;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (y > d) radars = -1;
            double sqrtd = sqrt(d*d - y*y);
            intervals.push_back(dd(x + sqrtd, x - sqrtd));
        }
        
        if (radars != -1) {
            sort(intervals.begin(), intervals.end());
            
            for (int i = 0; i < n; radars++) {
                s2 = intervals[i].first;
                while (++i < n && intervals[i].second <= s2) { }
            }
        }
        
        printf("Case %d: %d\n", t++, radars);
    }
    
    return 0;
}