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

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        bool v[] = {false, false, false, false, false};
        for (char &c : s) {
            if (c == 'a') v[0] = true;
            else if (c == 'e') v[1] = true;
            else if (c == 'i') v[2] = true;
            else if (c == 'o') v[3] = true;
            else if (c == 'u') v[4] = true;
        }

        bool panvocalica = true;
        for (bool &b : v)
            if (!b) {
                panvocalica = false;
                break;
            }

        cout << (panvocalica ? "SI" : "NO") << endl;
    }

    return 0;
}