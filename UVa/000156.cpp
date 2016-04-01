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
    string s;
    map<string, pair<string, int>> dict;
    while (cin >> s && s != "#") {
        string t = s;
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        sort(t.begin(), t.end());
        dict[t].first = s;
        dict[t].second++;
    }

    set<string> ananagrams;
    for (auto it = dict.begin(); it != dict.end(); ++it)
        if ((*it).second.second == 1) ananagrams.insert((*it).second.first);
    for (auto it = ananagrams.begin(); it != ananagrams.end(); ++it)
        cout << *it << endl;
    return 0;
}