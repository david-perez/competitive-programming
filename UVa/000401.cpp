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

int main() {
    string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string s2 = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

    map<char,char> m;

    for (int i = 0; i < s1.size(); i++) m[s1[i]] = s2[i];

    string out[2][2] = {
        {" -- is not a palindrome.", " -- is a mirrored string."},
        {" -- is a regular palindrome.", " -- is a mirrored palindrome."}
    };

    string s;
    while (cin >> s) {
        int a = 1, b = 1, i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j]) a = 0;
            if (s[i] != m[s[j]]) b = 0;
            i++, j--;
        }
        cout << s << out[a][b] << endl << endl;
    }

    return 0;
}