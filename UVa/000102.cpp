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
    int inp[9], b, moves;
    string s;
    
    while (cin >> inp[0]) {
        for (int i = 1; i < 9; i++) cin >> inp[i];
        
        s = "BCG";
        moves = inp[3] + inp[6] + inp[2] + inp[8] + inp[1] + inp[4];
        
        b = inp[3] + inp[6] + inp[1] + inp[7] + inp[2] + inp[5];
        if (b < moves) moves = b, s = "BGC";
        
        b = inp[5] + inp[8] + inp[0] + inp[6] + inp[1] + inp[4];
        if (b < moves) moves = b, s = "CBG";
        
        b = inp[5] + inp[8] + inp[1] + inp[7] + inp[0] + inp[3];
        if (b < moves) moves = b, s = "CGB";
        
        b = inp[4] + inp[7] + inp[0] + inp[6] + inp[2] + inp[5];
        if (b < moves) moves = b, s = "GBC";
        
        b = inp[4] + inp[7] + inp[2] + inp[8] + inp[0] + inp[3];
        if (b < moves) moves = b, s = "GCB";
        
        cout << s << ' ' << moves << endl;
    }

    return 0;
}
