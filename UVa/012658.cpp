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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
    int n, i, j;
    string s;
    string dummy;
    cin >> n >> dummy >> dummy >> dummy >> s >> dummy;
    
    for (i = 0, j = 0; j < n; i += 4, j++) {
        if (s[i] == '*') cout << "2";
        else if (s[i+1] == '*') cout << "1";
        else cout << "3";
    }
    cout << endl;

    return 0;
}