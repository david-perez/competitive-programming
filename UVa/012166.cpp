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
    int T;
    cin >> T; cin.get();
    while (T--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        map<ll, int> m;
        int depth = 0, nodes = 0, f = 0;
        while (ss) {
            char c = ss.peek();
            if (c == '[') depth++;
            else if (c == ']') depth--;
            else if (isdigit(c)) {
                ll v;
                ss >> v;
                nodes++;
                m[v * (1 << depth)]++;
                f = max(f, m[v * (1 << depth)]);
                continue;
            }

            ss >> c;
        }

        cout << nodes - f << endl;
    }

    return 0;
}