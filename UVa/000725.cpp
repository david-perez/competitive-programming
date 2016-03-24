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

int main() {
    int N, t = 0;
    while (cin >> N && N != 0) {
        if (t != 0) cout << endl;
        bool possible = false;
        for (int fghij = 1234; fghij <= 98765 / N; fghij++) {
            int abcde = fghij * N;
            bitset<10> d; if (fghij < 10000) d[0] = 1;
            int tmp = fghij;
            while (tmp)
                d[tmp % 10] = 1, tmp /= 10;
            tmp = abcde;
            while (tmp)
                d[tmp % 10] = 1, tmp /= 10;
            if (d.to_ulong() == (1 << 10) - 1) {
                possible = true;
                printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
            }
        }
        if (!possible) printf("There are no solutions for %d.\n", N);
        t++;
    }

    return 0;
}