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

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string s;
    while (getline(cin, s)) {
        int i = 0, j = 0;
        while (j < s.length()) {
            if (!isalpha(s[i])) {
                cout << s[i];
                i++, j++;
                continue;
            }

            while (j < s.length() && isalpha(s[j])) j++;

            // s[i...j-1] is a word
            if (is_vowel(tolower(s[i]))) {
                while (i != j) {
                    cout << s[i];
                    i++;
                }
                cout << "ay";
            } else {
                char c = s[i]; i++;
                while (i != j) {
                    cout << s[i];
                    i++;
                }
                cout << c << "ay";
            }
        }

        cout << endl;
    }

    return 0;
}