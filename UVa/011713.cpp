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

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string name1, name2;
    int t;
    
    cin >> t;
    while (t--) {
        bool ok = true;
        cin >> name1 >> name2;
        
        if (name1.size() != name2.size()) ok = false;
        for (int i = 0; i < name1.size() && ok; i++) {
            if (isVowel(name1[i]) && isVowel(name2[i])) continue;
            else ok = name1[i] == name2[i];
        }
        
        cout << (ok ? "Yes" : "No") << endl;
    }
    
    return 0;
}