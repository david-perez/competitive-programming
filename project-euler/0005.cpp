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
    int i = 2520;
    while (i += 20)
        if (i % 20 == 0 && i % 19 == 0 && i % 18 == 0 && i % 17 == 0 && i % 16 == 0 && i % 13 == 0 && i % 11 == 0 && i % 7 == 0) break;
    cout << i << endl;

    return 0;
}
