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

int N;
int prices[1000];
int weights[1000];
int memo[1000][30];

int knapsack(int id, int remW) {
    if (id == N || remW == 0) return 0;
    if (memo[id][remW] != -1) return memo[id][remW];

    if (remW-weights[id] >= 0)
        return memo[id][remW] = max(prices[id] + knapsack(id + 1, remW - weights[id]), knapsack(id + 1, remW));
    else
        return memo[id][remW] = knapsack(id+1, remW);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 1000; i++)
            for (int j = 0; j < 30; j++)
                memo[i][j] = -1;

        for (int i = 0; i < N; i++)
            cin >> prices[i] >> weights[i];
        int maxValue = 0;
        int G;
        cin >> G;
        while (G--) {
            int mw;
            cin >> mw;
            maxValue += knapsack(0, mw);
        }
        cout << maxValue << endl;
    }

    return 0;
}