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

int main() {
    map<string, char> us; // up-shift characters
    map<string, char> ds; // down-shift characters
    string s;

    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        if (i != 27 && i != 31) {
            bitset<5> b(i);
            ds[b.to_string()] = s[i];
        }

    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        if (i != 27 && i != 31) {
            bitset<5> b(i);
            us[b.to_string()] = s[i];
        }

    while (getline(cin, s)) {
        bool sd = true; // shift-down pressed as initial state
        for (int i = 0; i < s.length(); i += 5) {
            string t = s.substr(i, 5);
            if (t == "11011") sd = true;
            else if (t == "11111") sd = false;
            else if (sd) cout << ds[t];
            else cout << us[t];
        }

        cout << endl;
    }

    return 0;
}