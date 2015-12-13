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

bool ugly(long i) {
    while (i % 5 == 0) i /= 5;
    while (i % 3 == 0) i /= 3;
    while (i % 2 == 0) i /= 2;
    return i == 1;
}

int main() {
    /*
    int c = 0; long i = 1;
    while (c != 1500) {
        if (ugly(i)) c++;
        i++;
    }
    printf("The 1500'th ugly number is %d.\n", i-1);
    */
    printf("The 1500'th ugly number is 859963392.\n");
    
    return 0;
}
