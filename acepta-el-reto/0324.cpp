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

int gcd(int a, int b) {
    while (b) {
        int t = b; b = a%b; a = t;
    }
    return a;
}

int done(vector<bool> &d) {
    for (int i = 0; i < d.size(); i++)
        if (d[i] == true) return i;
    return -1;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vi b; vector<bool> d(n, true);
        while (n--) {
            int mol; cin >> mol;
            b.push_back(mol-1);
        }

        int i = done(d);
        int lcm = 1;
        while (i != -1) {
            int cnt = 1, j = i; d[i] = false;
            while (b[i] != j) {
                i = b[i];
                d[i] = false;
                cnt++;
            }
            lcm = lcm * cnt / gcd(lcm, cnt);
            i = done(d);
        }

        cout << lcm << endl;
    }

    return 0;
}