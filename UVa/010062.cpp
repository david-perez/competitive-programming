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

struct cmp {
    bool operator() (const ii &a, ii &b) {
        return a.second > b.second
                || (a.second == b.second && a.first < b.first);
    }
};

int main() {
    string s;
    getline(cin, s);
    while (true) {
        map<int, int> m;
        for (char &c : s)
            m[c]++;

        priority_queue<ii, vii, cmp> pq;
        for (auto &p: m)
            pq.push(p);

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            cout << p.first << ' ' << p.second << endl;
        }

        if (!getline(cin, s)) break;
        else cout << endl;
    }

    return 0;
}