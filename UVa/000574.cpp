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

int t, n;
vi nums;
set<string> sols;
vi choice;

string get_sol() {
    stringstream ss;
    for (int i = 0; i < choice.size()-1; i++)
        ss << choice[i] << '+';
    ss << choice[choice.size()-1];
    return ss.str();
}

void backtrack(int k, int sum) {
    if (sum > t) return;
    if (k == n) {
        if (sum == t) {
            string s = get_sol();
            if (sols.find(s) == sols.end()) {
                sols.insert(s);
                cout << s << endl;
            }
        }
        return;
    }

    choice.push_back(nums[k]);
    backtrack(k+1, sum + nums[k]);
    choice.pop_back();
    backtrack(k+1, sum);
}

int main() {
    while (cin >> t >> n && n != 0) {
        choice.clear();
        nums.clear();
        sols.clear();
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            nums.push_back(x);
        }
        printf("Sums of %d:\n", t);
        backtrack(0, 0);
        if (sols.empty()) cout << "NONE" << endl;
    }

    return 0;
}