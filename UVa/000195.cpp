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

bool compare(char a, char b) {
    if (isupper(a) && isupper(b)) return a < b;
    if (islower(a) && islower(b)) return a < b;
    if (isupper(a)) return tolower(a) <= b;
    return a < tolower(b);
}

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        sort(s.begin(), s.end(), compare);
        do
            cout << s << endl;
        while (next_permutation(s.begin(), s.end(), compare));
    }

    return 0;
}