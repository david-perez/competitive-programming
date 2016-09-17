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

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        map<int, string> m;
        set<string> words;
        int i = 0;

        string s;
        while (getline(cin, s) && s != "END") {
            for (char &c : s)
                if (!isalpha(c))
                    c = ' ';

            stringstream ss(s);
            string t;
            while (ss >> t) {
                m[i] = t;
                words.insert(t);
                i++;
            }
        }

        map<string, int> m2; // how many times a word has appeared in the considered interval
        int P = 0, Q = m.size();
        for (int p = 0, q = 0; p < m.size() && q < m.size(); q++) {
            m2[m[q]]++;
            words.erase(m[q]);
            while (p < m.size() && words.empty()) {
                if (q - p < Q - P) {
                    P = p;
                    Q = q;
                }

                m2[m[p]]--;
                if (m2[m[p]] == 0)
                    words.insert(m[p]);
                p++;
            }
        }

        printf("Document %d: %d %d\n", t, P+1, Q+1);
    }


    return 0;
}