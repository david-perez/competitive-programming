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
    while (cin >> n) {
        stack<int> s; bool bs = true;
        queue<int> q; bool bq = true;
        priority_queue<int> pq; bool bpq = true;

        while (n--) {
            int op, x; cin >> op >> x;
            if (op == 1) {
                if (bs) s.push(x);
                if (bq) q.push(x);
                if (bpq) pq.push(x);
            } else {
                if (bs) {
                    if (s.empty() || s.top() != x) bs = false;
                    else s.pop();
                }

                if (bq) {
                    if (q.empty() || q.front() != x) bq = false;
                    else q.pop();
                }

                if (bpq) {
                    if (pq.empty() || pq.top() != x) bpq = false;
                    else pq.pop();
                }
            }
        }

        if (!bs && !bq && !bpq) cout << "impossible" << endl;
        else if (bs && !bq && !bpq) cout << "stack" << endl;
        else if (!bs && bq && !bpq) cout << "queue" << endl;
        else if (!bs && !bq && bpq) cout << "priority queue" << endl;
        else cout << "not sure" << endl;
    }

    return 0;
}