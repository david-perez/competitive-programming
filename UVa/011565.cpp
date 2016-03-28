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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B, C; cin >> A >> B >> C; bool sol = false;
        for (int x = -21; x <= 21 && !sol; x++) if (x*x <= C)
            for (int y = -100; y <= 100 && !sol; y++) if (x != y && x*x + y*y <= C)
                for (int z = -100; z < 100 && !sol; z++)
                    if (x != z && y != z && x + y + z == A && x*y*z == B && x*x + y*y + z*z == C)
                        printf("%d %d %d\n", x, y, z), sol = true;
        if (!sol) cout << "No solution." << endl;
    }

    return 0;
}