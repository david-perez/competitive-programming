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
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int main() {
    int T;
    
    cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1;
        
        int n;
        for (n = 0; s1 != "6174"; n++) {
            while(s1.length() != 4)
                s1.insert(0, "0");
            
            sort(s1.begin(), s1.end());
            s2 = s1;
            sort(s2.begin(), s2.end(), greater<char>());
            int r = stoi(s2) - stoi(s1);
            if (r == 0) {
                n = 8;
                break;
            }
            s1 = to_string(r);
        }
        
        cout << n << endl;
    }
    
    return 0;
}