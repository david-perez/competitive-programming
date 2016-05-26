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
    int N;
    while (cin >> N && N != 0) {
        priority_queue<int, vi, greater<int>> pq;
        while (N--) {
            int x; cin >> x;
            pq.push(x);
        }

        if (N == 1) {
            cout << pq.top() << endl;
            continue;
        }

        int cost = 0;
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            cost += x + y;
            if (!pq.empty()) pq.push(x + y);
        }

        cout << cost << endl;
    }

    return 0;
}