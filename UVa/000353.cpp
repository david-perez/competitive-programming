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

bool is_palindrome(string s) {
    for (int i = 0, j = s.length() - 1; i <= j; i++, j--)
        if (s[i] != s[j]) return false;

    return true;
}

int main() {
    string s;
    while (getline(cin, s)) {
        set<string> palindromes;
        for (int i = 0; i < s.length(); i++)
            for (int j = i; j < s.length(); j++) {
                string t = s.substr(i, j-i+1);
                if (is_palindrome(t))
                    palindromes.insert(t);
            }

        printf("The string '%s' contains %d palindromes.\n", s.c_str(), palindromes.size());
    }

    return 0;
}