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
    int n;
    string s;
    
    cin >> n; cin.get();
    while (n--) {
        stack<char> st;
        bool ok = true;
        
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[') st.push(s[i]);
            else if (st.empty() || (st.top() == '(' && s[i] == ']') || (st.top() == '[' && s[i] == ')')) {
                ok = false;
                break;
            } else st.pop();
        }
        
        cout << (ok && st.empty() ? "Yes" : "No") << endl;
    }
    
    return 0;
}