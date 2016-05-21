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

int main() {
    map<char, int> m;
    m['B'] = m['F'] = m['P'] = m['V'] = 1;
    m['C'] = m['G'] = m['J'] = m['K'] = m['Q'] = m['S'] = m['X'] = m['Z'] = 2;
    m['D'] = m['T'] = 3;
    m['L'] = 4;
    m['M'] = m['N'] = 5;
    m['R'] = 6;

    string s;
    while (getline (cin, s)) {
        int last = -1;
        for (char &c : s) {
            if (m.count(c) == 0) {
                last = -1;
                continue;
            }
            if (m[c] == last) continue;
            cout << m[c];
            last = m[c];
        }

        cout << endl;
    }

    return 0;
}