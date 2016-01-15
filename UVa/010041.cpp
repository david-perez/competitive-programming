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
    int t, r, b;
    
    cin >> t;
    while (t--) {
        vi v;
        
        cin >> r;
        for (int i = 0; i < r; i++) {
            cin >> b;
            v.push_back(b);
        }
        
        nth_element(v.begin(), v.begin()+v.size()/2, v.end());
        int median = v[v.size()/2];
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += abs(median - v[i]);
        
        cout << sum << endl;
    }
    
    return 0;
}