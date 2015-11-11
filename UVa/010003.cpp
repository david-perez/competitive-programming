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

int sols[50][50];
int cuts[50];

int fun (int a, int b) { // returns the min cost of cutting stick cuts[a]...cuts[b] with the cuts in cuts[a+1...b-1]
    if (sols[a][b] != -1) return sols[a][b];
    if (b == a+1) {
        sols[a][b] = 0;
        return 0;
    }
    int minCost = INT_MAX;
    int c1, c2;
    for (int i = a + 1; i < b; i++) {
        c1 = fun(a, i);
        c2 = fun(i, b);
        minCost = min(minCost, c1 + c2 + cuts[b] - cuts[a]);
    }
    sols[a][b] = minCost;
    return minCost;
}

int main() {
    int l, n;
    
    cin >> l;
    while(l != 0) {
        cin >> n;
        
        cuts[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> cuts[i];
        cuts[n + 1] = l;
        
        for(int i = 0; i < n + 2; i++)
            for(int j = 0; j < n + 2; j++)
                sols[i][j] = -1;
        
        cout << "The minimum cutting is " << fun(0, n + 1) << "." << endl;
        
        cin >> l;
    }
    
    return 0;
}
