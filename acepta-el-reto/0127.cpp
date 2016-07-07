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

int main() {
    int T;
    cin >> T;
    while (T--) {
        deque<pair<int, string>> q;
        string s;
        for (int i = 0; cin >> s && s != "F"; i++)
            q.push_back(make_pair(i, s));

        int camas, words;
        cin >> camas >> words;

        if (q.size() <= camas) {
            cout << "TODOS TIENEN CAMA" << endl;
            continue;
        } else if (camas == 0) {
            cout << "NADIE TIENE CAMA" << endl;
            continue;
        }

        while (q.size() != camas) {
            for (int i = 0; i < words - 1; i++) {
                q.push_back(q.front());
                q.pop_front();
            }

            q.pop_front();
        }

        sort(q.begin(), q.end());
        for (int i = 0; i < q.size() - 1; i++)
            cout << q[i].second << ' ';
        cout << q[q.size() - 1].second << endl;
    }

    return 0;
}