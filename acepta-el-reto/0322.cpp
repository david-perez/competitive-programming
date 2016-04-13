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

int memo[1000][1000];
string s;

int patindrome(int i, int j) {
    if (i > j) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    if (i == j) return memo[i][j] = 1;

    if (s[i] == s[j])
        return memo[i][j] = 2 + patindrome(i+1, j-1);
    else
        return memo[i][j] = max(patindrome(i+1, j), patindrome(i, j-1));
}

int main() {
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++)
            for (int j = 0; j < s.length(); j++)
                memo[i][j] = -1;
        patindrome(0, s.length()-1);

        stack<char> b;
        int i = 0, j = s.length()-1;
        while (i <= j) {
            if (s[i] == s[j]) {
                cout << s[i];
                if (i != j) b.push(s[i]);
                i++, j--;
            } else if (memo[i][j] == memo[i+1][j]) i++; // eliminar patito izquierdo primero
            else j--;
        }
        while (!b.empty()) cout << b.top(), b.pop();
        cout << endl;
    }

    return 0;
}