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
    int T;
    
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, wall1, wall2, highs = 0, lows = 0;
        
        cin >> N;
        cin >> wall1; N--;
        while (N--) {
            cin >> wall2;
            if (wall2 > wall1) highs++;
            else if (wall2 < wall1) lows++;
            wall1 = wall2;
        }
        
        printf("Case %d: %d %d\n", i, highs, lows);
    }
    
    return 0;
}