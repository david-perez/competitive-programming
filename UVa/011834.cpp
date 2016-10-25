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
#include <numeric>

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
#define PI acos(-1)
#define EPS 1e-9

struct point {
    int x, y;
    point(int _x, int _y) : x(_x), y(_y) {}
};

int distSq(point p1, point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

int main() {
    int L, C, R1, R2;
    while (cin >> L >> C >> R1 >> R2 && !(L == 0 && C == 0 && R1 == 0 && R2 == 0)) {
        point p1(R1, R1), p2(L-R2, C-R2);
        if (2*R1 > min(L, C) || 2*R2 > min(L, C) || (distSq(p1, p2) < (R1+R2)*(R1+R2))) cout << 'N' << endl;
        else cout << 'S' << endl;
    }

    return 0;
}