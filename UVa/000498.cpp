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
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {
        stringstream ss(s); vi cn; int c;
        while (ss >> c) cn.push_back(c);

        stringstream st(t); int xm;
        while (st >> xm) {
            int ev = cn[0];
            for (int i = 1; i < cn.size(); i++)
                ev = ev*xm + cn[i];
            cout << ev; if (!st.eof()) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}