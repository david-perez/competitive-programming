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

bool isvowel(char &c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    int L, N;
    cin >> L >> N;
    map<string, string> irregular;
    while (L--) {
        string s, t; cin >> s >> t;
        irregular.insert(make_pair(s, t));
    }
    while (N--) {
        string s; cin >> s; int l = s.length();
        auto it = irregular.find(s);
        if (it != irregular.end())
            cout << it->second << endl;
        else if (l >= 2 && !isvowel(s[l-2]) && s[l-1] == 'y') {
            s.pop_back();
            cout << s << "ies" << endl;
        } else if (s[l-1] == 'o' || s[l-1] == 's' || s[l-1] == 'x' || (l >= 2 && ((s[l-2] == 'c' && s[l-1] == 'h') || (s[l-2] == 's' && s[l-1] == 'h'))))
            cout << s << "es" << endl;
        else
            cout << s << "s" << endl;
    }

    return 0;
}