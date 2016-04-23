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
    int n;
    while (cin >> n && n != 0) {
        int popular = 0;
        map<set<int>, int> m;
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int i = 0; i < 5; i++) {
                int course; cin >> course;
                s.insert(course);
            }
            popular = max(popular, ++m[s]);
        }
        int cnt = 0;
        for (auto &p : m)
            if (p.second == popular) cnt += popular;
        cout << cnt << endl;
    }

    return 0;
}