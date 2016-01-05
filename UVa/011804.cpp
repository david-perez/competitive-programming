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

struct player {
    int a, d;
    string n;
    bool operator < (const player x) const {
        return (a > x.a) || (a == x.a && d < x.d) || (a == x.a && d == x.d && n.compare(x.n) < 0);
    }
} p[10];

bool sort_name(const player y, const player x) {
    return (y.n).compare(x.n) < 0;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < 10; j++)
            cin >> p[j].n >> p[j].a >> p[j].d;

        sort(p, p + 10);
        sort(p, p + 5, sort_name);
        sort(p + 5, p + 10, sort_name);
        
        printf("Case %d:\n(%s, %s, %s, %s, %s)\n", i, p[0].n.c_str(), p[1].n.c_str(), p[2].n.c_str(), p[3].n.c_str(), p[4].n.c_str());
        printf("(%s, %s, %s, %s, %s)\n", p[5].n.c_str(), p[6].n.c_str(), p[7].n.c_str(), p[8].n.c_str(), p[9].n.c_str());
    }
    
    return 0;
}