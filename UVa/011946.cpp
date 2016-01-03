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

char decode(char c) {
    if (c == '3') c = 'E';
    else if (c == '0') c = 'O';
    else if (c == '1') c = 'I';
    else if (c == '4') c = 'A';
    else if (c == '9') c = 'P';
    else if (c == '8') c = 'B';
    else if (c == '5') c = 'S';
    else if (c == '7') c = 'T';
    else if (c == '6') c = 'G';
    else if (c == '2') c = 'Z';
    
    return c;
}

int main() {
    int t; string s;
    
    cin >> t; cin.get();
    while (t--) {
        getline(cin, s);
        while (s.size() > 0) {
            for (int i = 0; i < s.size(); i++)
                s[i] = decode(s[i]);
            cout << s << endl;
            getline(cin, s);
        }
        if (t > 0) cout << endl;
    }
    
    return 0;
}
