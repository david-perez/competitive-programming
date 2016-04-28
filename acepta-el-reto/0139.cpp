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
    int n;
    while (cin >> n && n != 0) {
        if (n == 1) {
            cout << "1 -> cubifinito." << endl;
            continue;
        }
        set<int> s;
        s.insert(n);
        cout << n << ' ';
        while (true) {
            int sum = 0;
            while (n != 0) {
                int d = n % 10;
                sum += d*d*d;
                n /= 10;
            }
            if (sum == 1) {
                cout << "- 1 -> cubifinito." << endl;
                break;
            } else if (s.count(sum) == 1) {
                printf("- %d -> no cubifinito.\n", sum);
                break;
            } else {
                s.insert(sum);
                printf("- %d ", sum);
                n = sum;
            }
        }
    }

    return 0;
}