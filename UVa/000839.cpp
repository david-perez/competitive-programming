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

bool isBalanced(int wl, int dl, int wr, int dr, int &totalW) {
    bool bl = true, br = true;
    if (wl == 0) {
        int wll, dll, wlr, dlr;
        cin >> wll >> dll >> wlr >> dlr;
        bl = isBalanced(wll, dll, wlr, dlr, wl);
    }
    if (wr == 0) {
        int wrl, drl, wrr, drr;
        cin >> wrl >> drl >> wrr >> drr;
        br = isBalanced(wrl, drl, wrr, drr, wr);
    }
    totalW = wl + wr;
    return bl && br && (wl * dl == wr * dr);
}

int main() {
    int t, wl, dl, wr, dr, totalW;
    cin >> t;
    while (t--) {
        cin >> wl >> dl >> wr >> dr;
        cout << (isBalanced(wl, dl, wr, dr, totalW) ? "YES" : "NO") << endl;
        if (t) cout << endl;
    }

    return 0;
}