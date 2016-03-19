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

int numbers[12];

int main() {
    int k, t = 0;
    while (cin >> k && k != 0) {
        if (t != 0) cout << endl;
        for (int i = 0; i < k; i++)
            cin >> numbers[i];
        vi perms(k, 1);
        for (int i = 0; i < 6; i++) perms[i] = 0; // 0 -> chosen
        do { // print permutation
            int p = 0, i = 0;
            while (p < 6) {
                if (perms[i] == 0) {
                    cout << numbers[i];
                    p++;
                    if (p < 6) cout << " ";
                }
                i++;
            }
            cout << endl;
        } while (next_permutation(perms.begin(), perms.end()));
        t++;
    }

    return 0;
}