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
#define PI acos(-1)
#define EPS 1e-9

void bst(int left, int right, int H) {
    if (H == 0 || left > right) return;

    int root = max(left, right - ((1 << (H-1)) - 1));

    printf(" %d", root);

    bst(left, root-1, H-1);
    bst(root+1, right, H-1);
}

int main() {
    int N, H;
    for (int t = 1; cin >> N >> H && !(N == 0 && H == 0); t++) {
        printf("Case %d:", t);
        if ((1 << H) - 1 < N) {
            cout << " Impossible." << endl;
            continue;
        }

        if (H > N) H = N;

        bst(1, N, H);
        cout << endl;
    }

    return 0;
}