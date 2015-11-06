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

unsigned long collatz_cycle(unsigned long n) {
    if (n == 1) return 1;
    return 1 + (n % 2 == 0 ? collatz_cycle(n/2) : collatz_cycle(3*n+1));
}

int main() {
    unsigned long i, j, ans;
    while (scanf("%ld %ld", &i, &j) == 2) {
        ans = 0;
        for (unsigned long k = min(i, j); k <= max(i, j); k++)
            ans = max(ans, collatz_cycle(k));
        printf("%ld %ld %ld\n", i, j, ans);
    }

    return 0;
}