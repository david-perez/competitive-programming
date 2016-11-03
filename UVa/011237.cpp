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
#include <numeric>

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
#define PI acos(-1)
#define EPS 1e-9

int sum[100000];
int seen_at[100000];

int main() {
    int c, n;
    while (cin >> c >> n && !(n == 0 && c == 0)) {
        vi v;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        fill(seen_at, seen_at+c, -1);
        seen_at[0] = 0;
        sum[0] = 0;

        for (int i = 1; i <= n; i++) {
            sum[i] = (sum[i-1] + v[i-1]) % c;
            if (seen_at[sum[i]] != -1) {
                for (int j = seen_at[sum[i]] + 1; j <= i; j++) {
                    printf("%d", j);
                    if (j != i) cout << ' ';
                }
                cout << endl;
                break;
            } else seen_at[sum[i]] = i;
        }
    }

    return 0;
}