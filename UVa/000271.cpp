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

bool isHedonian(string &s) {
    int valid = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        if ('p' <= s[i] && s[i] <= 'z') valid++;
        else if (s[i] == 'N') {
            if (valid < 1) return false;
        } else if (s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'I') {
            if (valid < 2) return false;
            else valid--;
        } else return false;
    }

    return valid == 1;
}

int main() {
    string s;
    while (getline(cin, s))
        cout << (isHedonian(s) ? "YES" : "NO") << endl;

    return 0;
}