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

string s;

bool slump(int i, int j) {
    if (j < i) return false;
    if (j-i+1 < 3) return false;
    if (s[i] != 'D' && s[i] != 'E') return false;
    if (s[i+1] != 'F') return false;

    i += 2;
    while (i < j && s[i] == 'F') i++;

    if (i == j && s[i] == 'G') return true;
    else return slump(i, j);
}

bool slimp(int i, int j) {
    if (j < i) return false;

    if (i+1 == j && s[i] == 'A' && s[j] == 'H') return true;

    if (j-i+1 >= 3) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[j] == 'C' && slimp(i+2, j-1)) return true;
        if (s[i] == 'A' && s[j] == 'C' && slump(i+1, j-1)) return true;
    }

    return false;
}

bool slurpy() {
    for (int i = 0; i <= s.length()-2; i++)
        if (slimp(0, i) && slump(i+1, s.length()-1)) return true;

    return false;
}

int main() {
    cout << "SLURPYS OUTPUT" << endl;

    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        cout << (slurpy() ? "YES" : "NO") << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}