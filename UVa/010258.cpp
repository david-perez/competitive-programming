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

struct cmp {
    bool operator() (const pair<ii, pair<bool, int>> &a, const pair<ii, pair<bool, int>> &b) {
        return a.first.first > b.first.first
                || (a.first.first == b.first.first && a.first.second < b.first.second)
                || (a.first.first == b.first.first && a.first.second == b.first.second && (a.second.first && !b.second.first))
                || (a.first.first == b.first.first && a.first.second == b.first.second && (a.second.first && b.second.first) && a.second.second < b.second.second);
    }
};

int main() {
    int T;
    cin >> T; cin.get(); cin.get();
    while (T--) {
        int penalties[100][10]; memset(penalties, 0, sizeof penalties);
        vector<pair<ii, pair<bool, int>>> scores(100); // (solved, penalty, submitted, contestant number)
        for (int i = 0; i < scores.size(); i++) {
            scores[i].first.first = 0;
            scores[i].first.second = 0;
            scores[i].second.first = false;
            scores[i].second.second = i+1;
        }
        string s;

        while (getline(cin, s) && s.length() > 0) {
            stringstream ss(s);
            int c, p, t; char L; ss >> c >> p >> t >> L; c--;
            if (L == 'C' && penalties[c][p] != -1) { // only account for first correct submission.
                scores[c].first.first++;
                scores[c].first.second += penalties[c][p] + t;
                penalties[c][p] = -1;
            } else if (L == 'I' && penalties[c][p] != -1)
                penalties[c][p] += 20;
            scores[c].second.first = true;
        }

        sort(scores.begin(), scores.end(), cmp());
        for (auto &p : scores) {
            if (!p.second.first) break;
            printf("%d %d %d\n", p.second.second, p.first.first, p.first.second);
        }

        if (T > 0) cout << endl;
    }

    return 0;
}