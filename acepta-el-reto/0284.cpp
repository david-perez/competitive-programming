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
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int money[8] = {200, 100, 50, 20, 10, 5, 2, 1};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int cost, given;
        cin >> cost >> given;
        if (cost > given) {
            printf("DEBE %d\n", cost - given);
            continue;
        }

        cost = given - cost;

        vi change(8, 0);
        for (int i = 0; i < 8; i++) {
            change[i] = cost / money[i];
            cost -= money[i] * change[i];
        }

        for (int i = 0; i < 7; i++)
            cout << change[i] << " ";
        cout << change[7] << endl;
    }

    return 0;
}