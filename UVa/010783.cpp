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

int naive(int a, int b) { // O(n)
    int s = 0;
    for (int i = a; i <= b; i++)
        s += i % 2 == 0 ? 0 : i;
    return s;
}

int fun(int a, int b) { // O(1)
    if (a % 2 == 0 && b % 2 == 0) return (b*b-a*a)/4;
    else if (a % 2 == 1 && b % 2 == 0) return (b*b-(a-1)*(a-1))/4;
    else if (a % 2 == 0 && b % 2 == 1) return ((b+1)*(b+1)-a*a)/4;
    else return ((b+1)*(b+1)-(a-1)*(a-1))/4;
}

int main() {
    int t, a, b;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        printf("Case %d: %d\n", i, fun(a, b));
    }

    return 0;
}