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

struct constraint {
    char c;
    bool b;
};

struct cmp {
    bool operator() (const vector<constraint> &a, const vector<constraint> &b) {
        return a.size() < b.size();
    }
};

vector<constraint> parseConstraints(string &s) {
    vector<constraint> ret;
    stringstream ss(s);
    char b;
    while (ss >> b && b != ';') {
        char c;
        ss >> c;
        constraint ct;
        ct.c = c;
        ct.b = b == '+';
        ret.push_back(ct);
    }

    return ret;
}

vector<vector<constraint>> l; // list of all constraints
map<char, bool> sol; // imposed constraints

bool backtrack(int k) { // returns true if a solution exists
    if (k == l.size())
        return true;

    for (int i = 0; i < l[k].size(); i++) {
        char t = l[k][i].c; // topping of the constraint being considered
        if (sol.count(t) == 0) { // the constraint has not been considered yet, impose it.
            sol[t] = l[k][i].b;
            if (backtrack(k+1)) return true;
        } else if (sol[t] == l[k][i].b) // the constraint has already been imposed
            if (backtrack(k+1)) return true;

        // this constraint is in conflict with a previously imposed constraint, go to next constraint
    }

    return false;
}

int main() {
    string s;
    while (getline(cin, s) && s != "") {
        l.clear();
        l.push_back(parseConstraints(s));

        while (getline(cin, s) && s != ".")
            l.push_back(parseConstraints(s));

        sort(l.begin(), l.end(), cmp()); // constraint lists with "less" constraints are considered first

        sol.clear();
        if (backtrack(0)) {
            cout << "Toppings: ";
            for (auto &p : sol)
                cout << p.first;
            cout << endl;
        } else
            cout << "No pizza can satisfy these requests." << endl;
    }

    return 0;
}