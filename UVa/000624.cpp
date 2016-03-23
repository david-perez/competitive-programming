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
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

int N, nt;
vi tracks, bestsol, ps;
int bestsum;

void backtrack(vi &sol, int sum, int k) {
    if (k == nt) {
        if (bestsum < sum) {
            bestsol = sol;
            bestsum = sum;
        }
        return;
    }

    if (sum + ps[k] <= bestsum) return; // prune

    if (sum + tracks[k] <= N) {
        sol.push_back(tracks[k]);
        backtrack(sol, sum + tracks[k], k+1);
        sol.pop_back();
    }
    backtrack(sol, sum, k+1);
}

int main() {
    while (cin >> N) {
        cin >> nt;
        tracks.clear();
        for (int i = 0; i < nt; i++) {
            int d; cin >> d;
            tracks.push_back(d);
        }
        ps.assign(nt, 0); ps[nt-1] = tracks[nt-1];
        for (int i = nt-2; i >= 0; i--)
            ps[i] = tracks[i] + ps[i+1];

        vi sol; int sum = 0; bestsum = 0;
        backtrack(sol, sum, 0);
        for (int i = 0; i < bestsol.size(); i++)
            printf("%d ", bestsol[i]);
        printf("sum:%d\n", bestsum);
    }

    return 0;
}