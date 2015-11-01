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

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        double s = 0.0;
        int x1, x2, y1, y2;
        cin >> x1 >> y1; n--;
        while (n--) {
            cin >> x2 >> y2;
            s += 0.5 * (-y1-y2) * (x2-x1);
            x1 = x2; y1 = y2;
        }
        
        int w;
        cin >> w;
        double vol = s * w;
        
        double initial_percent, consumed, rained;
        cin >> initial_percent >> consumed >> rained;
        
        double initial = initial_percent * vol / 100 ;
        initial -= consumed;
        if (initial < 0.0) {
            cout << "Lack of water. ";
            initial = 0;
        }
        initial += rained;
        if (initial > vol) {
            cout << "Excess of water. ";
            initial = vol;
        }
        cout << "Final percentage: " << ((int) (initial * 100 / vol )) << "%" << endl;
    }
    
    return 0;
}