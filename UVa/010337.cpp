#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
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

int w[10][1000];
int f[10][1001];

int main() {
    int N;
    cin >> N;
    while (N--) {
        int X; cin >> X;
        X /= 100;
        for (int i = 9; i >= 0; i--)
            for (int j = 0; j <= X-1; j++) {
                cin >> w[i][j];
                f[i][j] = 70*X; // max fuel (climbing with headwind 10 for X steps)
            }
        for (int i = 9; i >= 1; i--)
            f[i][X] = 70*X;
        f[0][X] = 0; // we need 0 units of fuel to get from X at altitude 0 to X at altitude 0

        for (int j = X-1; j >= 0; j--)
            for (int i = 9; i >= 0; i--) {
                if (i == 9)
                    f[i][j] = min(30 + f[i][j+1], 20 + f[i-1][j+1]);
                else if (i == 0)
                    f[i][j] = min(30 + f[i][j+1], 60 + f[i+1][j+1]);
                else
                    f[i][j] = min(30 + f[i][j+1], min(20 + f[i-1][j+1], 60 + f[i+1][j+1]));
                f[i][j] -= w[i][j]; // headwind will add fuel, tailwind will subtract fuel
            }

        cout << f[0][0] << endl << endl;
    }

    return 0;
}