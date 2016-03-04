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
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int main() {
    int g; string r;
    bitset<10> b; bool honest = true;
    while (cin >> g && g != 0) {
        cin.get(); g--;
        getline(cin, r);
        if (r == "too high" || r == "too low") {
            if (r == "too high")
                for (int i = 9; i >= g; i--)
                    b[i] = 1;
            else
                for (int i = 0; i <= g; i++)
                    b[i] = 1;

            bool full = true;
            for (int i = 0; i < 10; i++)
                if (b[i] == 0) {
                    full = false;
                    break;
                }

            if (full) honest = false;
        } else {
            if (b[g] == 1) honest = false;
            cout << (honest ? "Stan may be honest" : "Stan is dishonest") << endl;
            b.reset(); honest = true;
        }
    }

    return 0;
}