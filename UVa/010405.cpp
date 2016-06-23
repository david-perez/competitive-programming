#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
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

string s1, s2;
int memo[1000][1000];

int lcs(int i, int j) {
    if (i == s1.size() || j == s2.size()) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    
    if (s1[i] != s2[j]) return memo[i][j] = max(lcs(i+1, j), lcs(i, j+1));
    return memo[i][j] = 1 + lcs(i+1, j+1);
}

int main() {
    while (getline(cin, s1) && getline(cin, s2)) {
        memset(memo, -1, sizeof memo);
        cout << lcs(0, 0) << endl;
    }

    return 0;
}