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

int main() {
    int N;
    while (cin >> N && N > 0) {
        int top = 1, north = 2, west = 3;
        while (N--) {
            string s;
            cin >> s;
            //     2
            //   3 1 4
            //     5
            // 6 is on 1's opposite side.
            int lastTop = top;
            if (s == "north") {
                top = 7 - north;
                north = lastTop;
            } else if (s == "south") {
                top = north;
                north = 7 - lastTop;
            } else if (s == "west") {
                top = 7 - west;
                west = lastTop;
            } else if (s == "east") {
                top = west;
                west = 7 - lastTop;
            }
        }

        cout << top << endl;
    }

    return 0;
}