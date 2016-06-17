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

void another_solution() {
    ll N = 4294967296; // 2^32
    ll n;

    while (cin >> n) {
        cout << n << " converts to ";

        if (n < 0)
            n = N + n;

        bitset<32> b(n);
        bitset<32> o;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 8; j++)
                o[8*(4-i) - 8 + j] = b[8*i + j];

        ll m = o.to_ulong();
        if (o[31] == 1) {
            m = N - m;
            cout << '-';
        }

        cout << m << endl;
    }
}

// Right-shifting negative numbers in C++ is implementation-defined. This forces a correct logical right shift.
int lsr(int x, int n) {
    return (int)((unsigned int)x >> n);
}

int main() {
    //another_solution();

    int n;
    while (cin >> n) {
        int b1 = n & (255 << 24);
        int b2 = n & (255 << 16);
        int b3 = n & (255 << 8);
        int b4 = n & (255);

        b1 = lsr(b1, 24);
        b2 >>= 8;
        b3 <<= 8;
        b4 <<= 24;

        printf("%d converts to %d\n", n, (b1|b2|b3|b4));
    }

    return 0;
}