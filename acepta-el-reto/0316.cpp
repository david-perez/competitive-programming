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
typedef vector<pair<int, double>> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int main() {
    int t;
    
    cin >> t;
    while(t--) {
        int n, ini = 1, fin = n, oini, ofin, osum = -10000, sum = -10000;
        int val;
        
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> val;
            if (val >= sum + val) ini = fin = i, sum = val;
            else fin++, sum += val;
            if (sum > osum) oini = ini, ofin = fin, osum = sum;
            else if (sum == osum && fin - ini < ofin - oini) oini = ini, ofin = fin;
        }
        
        printf("%d %d\n", oini, ofin);
    }
    
    return 0;
}