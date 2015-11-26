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
    int n, a, b; int v[3000];
    while (cin >> n) {
        if (n == 1) {
            cin >> a; // trash
            cout << "Jolly" << endl;
            continue;
        }
        
        for (int i = 0; i < n; i++) v[i] = 0;
        cin >> a;
        for (int i = 1; i < n; i++) {
            cin >> b;
            v[abs(b-a)] = 1;
            a = b;
        }
        
        int i = 1;
        for (; i < n; i++) {
            if (v[i] == 0) {
                cout << "Not jolly" << endl;
                break;
            }
        }
        if (i == n) cout << "Jolly" << endl;
    }

    return 0;
}