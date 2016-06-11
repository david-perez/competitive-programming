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

set<string> rots;
string t;

bool is_rot (string s) {
    if (s == t) return true;
    if (rots.count(s) != 0) return false;
    rots.insert(s);

    stringstream ssrr;
    ssrr << s[2] << s[1] << s[5] << s[0] << s[4] << s[3];
    string rr = ssrr.str();

    stringstream ssrl;
    ssrl << s[3] << s[1] << s[0] << s[5] << s[4] << s[2];
    string rl = ssrl.str();

    stringstream ssru;
    ssru << s[4] << s[0] << s[2] << s[3] << s[5] << s[1];
    string ru = ssru.str();

    stringstream ssrd;
    ssrd << s[1] << s[5] << s[2] << s[3] << s[0] << s[4];
    string rd = ssrd.str();

    return is_rot(rr) || is_rot(rl) || is_rot(ru) || is_rot(rd);
}

int main() {
    string s;
    while (getline(cin, s)) {
        rots.clear();
        t = s.substr(6, 6);
        cout << (is_rot(s.substr(0, 6)) ? "TRUE" : "FALSE") << endl;
    }

    return 0;
}