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
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
    int heights[50];
    int n, t = 1, s = 0, moves;
    cin >> n;
    while (n != 0) {
        s = 0;
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
            s += heights[i];
        }
        
        moves = 0;
        for (int i = 0; i < n; i++)
            if (heights[i] > s/n) moves += heights[i] - s/n;
        
        printf("Set #%d\n", t);
        printf("The minimum number of moves is %d.\n\n", moves);
        
        cin >> n;
        t++;
    }
    
    return 0;
}