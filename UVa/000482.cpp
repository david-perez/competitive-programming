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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin.get();
        getline(cin, s); // blank line between input sets
        
        vector<string> a;
        vector<int> p;
        map<int, string> m;
        stringstream ss;
        
        getline(cin, s);
        ss << s;
        while (ss >> s) p.push_back(stoi(s));
        for (int i = 0; i < p.size(); i++) {
            cin >> s;
            m[p[i]-1] = s;
        }
        
        for (int i = 0; i < p.size(); i++)
            cout << m[i] << endl;
        if (t > 0) cout << endl;
    }
    
    return 0;
}