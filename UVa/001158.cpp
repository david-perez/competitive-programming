#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <list>
#include <forward_list>
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
typedef unsigned long long ull;
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

#define INF 1000000000 // 10^9
#define PI acos(-1)
#define EPS 1e-9

int main() {
    int memo[400001];
    vector<int> v;
    for (int i = 1; i*i*i <= 400000; i++)
        v.push_back(i*i*i);
    for (int i = 1, j = 1; j <= 400000; i++, j += i*i)
        v.push_back(j);

    for (int i = 0; i <= 400000; i++) memo[i] = INT_MAX;
    memo[0] = 0;
    for (int &c : v)
        for (int n = c; n <= 400000; n++)
            memo[n] = min(memo[n], 1 + memo[n-c]);

    int N;
    while (cin >> N && N != -1)
        cout << memo[N] << endl;

    return 0;
}