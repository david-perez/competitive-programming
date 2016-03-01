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
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<vii> adjListT(n, vii());
        for (int i = 0; i < m; i++) {
            int r;
            cin >> r;
            vi filled;
            for (int j = 0; j < r; j++) {
                int c;
                cin >> c; c--;
                filled.push_back(c);
            }

            for (int j = 0; j < r; j++) {
                int a;
                cin >> a;
                adjListT[filled[j]].push_back(ii(i, a));
            }
        }

        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++) {
            cout << adjListT[i].size();

            if (adjListT[i].size() == 0) {
                cout << endl << endl;
                continue;
            }

            for (int j = 0; j < adjListT[i].size(); j++)
                printf(" %d", adjListT[i][j].first + 1);
            cout << endl;
            for (int j = 0; j < adjListT[i].size() - 1; j++)
                printf("%d ", adjListT[i][j].second);
            cout << adjListT[i][adjListT[i].size() - 1].second << endl;
        }
    }

    return 0;
}