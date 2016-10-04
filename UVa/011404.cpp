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

pair<int, string> memo[1000][1000];
bool vis[1000][1000];
string s;

pair<int, string> palindrome(int i, int j) {
    if (vis[i][j]) return memo[i][j];

    vis[i][j] = true;

    if (i == j) return memo[i][j] = make_pair(1, string(1, s[i]));
    if (i+1 == j)
        if (s[i] == s[j]) return memo[i][j] = make_pair(2, string(2, s[i]));
        else return memo[i][j] = make_pair(1, string(1, min(s[i], s[j])));

    if (s[i] == s[j]) {
        auto p = palindrome(i+1, j-1);
        p.first += 2;
        p.second = s[i] + p.second + s[j];
        return memo[i][j] = p;
    } else {
        auto p = palindrome(i+1, j);
        auto q = palindrome(i, j-1);
        return memo[i][j] = (p.first == q.first ? min(p, q) : max(p, q));
    }
}

int main() {
    while (cin >> s) {
        memset(vis, false, sizeof vis);
        cout << palindrome(0, s.length()-1).second << endl;
    }

    return 0;
}