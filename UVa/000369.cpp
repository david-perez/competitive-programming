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
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

long pascal[100][100];

long C(int n, int m) {
    if (pascal[n][m] != 0) return pascal[n][m];
    else if (m == 0 || m == n) return pascal[n][m] = 1;
    else return pascal[n][m] = C(n-1,m-1) + C(n-1,m);
}

int main() {
    int n, m;
    
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            pascal[i][j] = 0;
    
    while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0))
        printf("%d things taken %d at a time is %ld exactly.\n", n, m, C(n, m));
    
    return 0;
}