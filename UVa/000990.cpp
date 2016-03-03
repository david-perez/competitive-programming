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
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int t, w, n;
bitset<30> bestSol;
int bestVal, numTreasures;

void csearch(bitset<30> &sol, int val, vii &treasures, int k) {
    if (k == n || t == 0) {
        if (val > bestVal) {
            numTreasures = 0;
            bestVal = val;
            for (int i = 0; i < 30; i++) {
                bestSol[i] = sol[i];
                if (bestSol[i] == 1) numTreasures++;
            }
        }
        return;
    }

    int d = treasures[k].first;
    int v = treasures[k].second;

    if (t - 3*d*w >= 0) {
        val += v;
        t -= 3*d*w;
        sol[k] = 1;
        csearch(sol, val, treasures, k+1);
        val -= v;
        t += 3*d*w;
        sol[k] = 0;
    }

    csearch(sol, val, treasures, k+1);
}

int main() {
    int cases = 0;
    while (cin >> t >> w) {
        if (cases != 0) cout << endl;
        cin >> n;
        vii treasures;
        for (int i = 0; i < n; i++) {
            int d, v; cin >> d >> v;
            treasures.push_back(ii(d, v));
        }

        bestSol.reset(); bestVal = 0; numTreasures = 0;
        bitset<30> sol; int val = 0;
        csearch(sol, val, treasures, 0);

        cout << bestVal << endl;
        cout << numTreasures << endl;
        for (int i = 0; i < 30; i++) {
            if (bestSol[i] == 1)
                printf("%d %d\n", treasures[i].first, treasures[i].second);
        }
        cases++;
    }

    return 0;
}