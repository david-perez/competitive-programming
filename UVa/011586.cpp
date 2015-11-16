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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

using namespace std;

int main() {
    string b;
    int t; cin >> t; cin.get();
    while (t--) {
        int ff, mm, mf;
        getline(cin, b);
        ff = 0; mm = 0; mf = 0;
        for (int i = 0; i < b.size(); i += 3) {
            if (b[i] == 'M' && b[i+1] == 'M') mm++;
            else if (b[i] == 'F' && b[i+1] == 'F') ff++;
            else mf++;
        }
        cout << ((mm == ff && mf + mm + ff > 1) ? "LOOP" : "NO LOOP");
        cout << endl;
    }
    
    return 0;
}
