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

void print(vector<char> &perms) {
    for (int i = 0; i < perms.size(); i++)
        cout << perms[i];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int c, v; cin >> c >> v;
        vector<char> perms;
        for (int i = 0; i < c; i++) perms.push_back('C');
        for (int i = 0; i < v; i++) perms.push_back('V');
        print(perms);
        while (next_permutation(perms.begin(), perms.end())) {
            cout << " ";
            print(perms);
        }
        cout << endl;
    }

    return 0;
}