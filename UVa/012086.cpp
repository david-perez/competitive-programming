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

int LSOne (int i) {
    return (i & (-i));
}

class FenwickTree {
public:
    vi ft;

    FenwickTree(int n) {
        ft.assign(n+1, 0);
    }

    int rsq(int b) {
        int sum = 0;
        while (b > 0) {
            sum += ft[b];
            b -= LSOne(b);
        }

        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - rsq(a-1);
    }

    void adjust(int k, int v) {
        while (k < ft.size()) {
            ft[k] += v;
            k += LSOne(k);
        }
    }
};

int main() {
    int N;
    for (int t = 1; cin >> N && N != 0; t++) {
        if (t > 1) cout << endl;
        printf("Case %d:\n", t);

        vi v;
        FenwickTree ft(N);
        for (int i = 0; i < N; i++) {
            int r;
            cin >> r;
            ft.adjust(i+1, r);
            v.push_back(r);
        }

        cin.get();
        string s;
        while (getline(cin, s) && s != "END") {
            stringstream ss(s);
            string a;
            int x, y;
            ss >> a >> x >> y;

            if (a == "S") {
                ft.adjust(x, y - v[x-1]);
                v[x-1] = y;
            } else cout << ft.rsq(x, y) << endl;
        }
    }

    return 0;
}