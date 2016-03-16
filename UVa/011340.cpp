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
    int N;
    cin >> N;
    while (N--) {
        map<char, int> m;
        int nc; cin >> nc;
        while (nc--) {
            char c; int p;
            cin >> c >> p;
            m[c] = p;
        }

        int cents = 0;
        int K; cin >> K; cin.get();
        while (K--) {
            string s; getline(cin, s);
            for (int i = 0; i < s.size(); i++) {
                if (m.count(s[i])) cents += m[s[i]];
            }
        }

        printf("%.2f$\n", (double)cents / 100);
    }

    return 0;
}