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
    int N;
    cin >> N;
    while (N--) {
        int M;
        cin >> M;
        vi n1, n2;
        while (M--) {
            int x, y;
            cin >> x >> y;
            n1.push_back(x);
            n2.push_back(y);
        }

        int carry = 0;
        for (int i = n1.size() - 1; i >= 0; i--) {
            int r = n1[i] + n2[i] + carry;
            carry = 0;
            n1[i] = r % 10;
            carry += r / 10;
        }

        // You get AC even if both numbers start with a non-zero leading digit, and you only
        // output the first M digits of the result.
        for (int d : n1)
            cout << d;

        cout << endl;
        if (N > 0) cout << endl;
    }

    return 0;
}