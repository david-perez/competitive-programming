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

int main() {
    int T;
    cin >> T; cin.get();
    for (int t = 1; t <= T; t++) {
        string s;
        getline(cin, s);

        printf("Case %d: ", t);

        int i = 0;
        while (i < s.length()) {
            int j = i+1;
            int n = s[j] - '0';
            j++;
            while (j < s.length() && !isalpha(s[j])) {
                n = n*10 + (s[j] - '0');
                j++;
            }

            for (int k = 0; k < n; k++)
                cout << s[i];

            i = j;
        }

        cout << endl;
    }

    return 0;
}