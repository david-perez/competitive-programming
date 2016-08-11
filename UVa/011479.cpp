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

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll tr[3]; // ll because overflow may happen with ints.
        cin >> tr[0] >> tr[1] >> tr[2];
        sort(tr, tr+3);

        if (tr[2] >= tr[0] + tr[1] || tr[0] <= 0)
            printf("Case %d: Invalid\n", t);
        else if (tr[0] == tr[1] && tr[1] == tr[2])
            printf("Case %d: Equilateral\n", t);
        else if (tr[0] == tr[1] || tr[0] == tr[2] || tr[1] == tr[2])
            printf("Case %d: Isosceles\n", t);
        else
            printf("Case %d: Scalene\n", t);
    }

    return 0;
}