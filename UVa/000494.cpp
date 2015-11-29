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
    string s, buff;
    int c;
    while (getline(cin, s)) {
        c = 0;
        int p = s.size() - 1;
        for (int i = 0; i < p; i++) {
            while (i < p && !isalpha(s[i])) i++;
            while (i < p && isalpha(s[i])) {
                if (!isalpha(s[i+1])) c++;
                i++;
            }
        }
        cout << c << endl;
    }

    return 0;
}
