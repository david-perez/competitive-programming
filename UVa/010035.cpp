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
    int x, y, c, r;
    cin >> x >> y;
    while (!(x == 0 && y == 0)) {
        r = 0; c = 0;
        while (x != 0 || y != 0) {
            if ((x % 10) + (y % 10) + r > 9) {
                c++;
                r = 1;
            } else r = 0;
            x /= 10; y /= 10;
        }
        if (c == 0) printf("No carry operation.\n");
        else if (c == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n", c);
        
        cin >> x >> y;
    }

    return 0;
}