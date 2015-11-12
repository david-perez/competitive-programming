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
    int n, r, b;
    int returned[10001];
    while (scanf("%d %d", &n, &r) == 2) {
        for (int i = 1; i <= n; i++) {
            returned[i] = -1;
        }
        for (int i = 0; i < r; i++) {
            cin >> b;
            returned[b] = 0;
        }
        if (r == n) {
            cout << "*" << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (returned[i] == -1)
                cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}