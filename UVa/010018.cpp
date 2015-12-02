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

long reverse(long n) {
    long r = 0;
    while (n != 0) {
        r = r * 10 + (n % 10);
        n /= 10;
    }
    return r;
}

bool isPalindrome(long p, long &pp) {
    pp = reverse(p);
    return p == pp;
}

int main() {
    long n, p, pp;
    cin >> n;
    while (n--) {
        cin >> p;
        int i = 0;
        while (!isPalindrome(p, pp)) p += pp, i++;
        printf("%d %ld\n", i, p);
    }

    return 0;
}