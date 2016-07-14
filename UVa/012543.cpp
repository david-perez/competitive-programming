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
    string s;
    string t = "";
    int it, jt = 0;
    while (cin >> s && s != "E-N-D") {
        int i = 0, j = 0;
        while (j < s.length()) {
            if (!isalpha(s[j]) && s[j] != '-') {
                if (j - i > jt - it) {
                    t = s;
                    it = i;
                    jt = j;
                }
                i = j+1;
            }

            j++;
        }

        if (j - i > jt - it) {
            t = s;
            it = i;
            jt = j;
        }
    }

    for (int i = it; i < jt; i++)
        cout << (char) tolower(t[i]);
    cout << endl;

    return 0;
}