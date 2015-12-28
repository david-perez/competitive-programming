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
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
    int t, a, f;
    cin >> t;
    while (t--) {
        cin >> a >> f;
        while (f--) {
            for (int i = 1; i <= a; i++) {
                for (int j = 0; j < i; j++) cout << i;
                cout << endl;
            }
            for (int i = a-1; i >= 1; i--) {
                for (int j = 0; j < i; j++) cout << i;
                cout << endl;
            }
            if (t || f) cout << endl;
        }
    }
    
    return 0;
}