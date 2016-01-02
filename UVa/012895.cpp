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

long d[10];

int main() {
    long t, a, orig, total;
    cin >> t;
    while (t--) {
        cin >> a;
        orig = a;
        int i = 0;
        while (a > 0) {
            d[i] = a % 10;
            a /= 10;
            i++;
        }
        
        total = 0;
        for (int j = 0; j < i; j++)
            total += (long) pow(d[j], i);
        
        
        if (total == orig) cout << "Armstrong" << endl;
        else cout << "Not Armstrong" << endl;
    }
    
    return 0;
}
