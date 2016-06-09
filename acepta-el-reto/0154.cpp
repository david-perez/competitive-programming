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

string m = "BCDFGHJKLMNPQRSTVWXYZ";

char next_char(char c) {
    return m[(m.find(c) + 1) % m.length()];
}

int main() {
    int x;
    string s;

    while (cin >> x >> s && !(x == 9999 && s == "ZZZ")) {
        if (x == 9999) {
            s[2] = next_char(s[2]);
            if (s[2] == 'B') {
                s[1] = next_char(s[1]);
                if (s[1] == 'B')
                    s[0] = next_char(s[0]);
            }
        }

        printf("%04d %s\n", (x+1) % 10000, s.c_str());
    }

    return 0;
}