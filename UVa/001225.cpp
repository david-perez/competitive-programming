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

string sols[10000];

void generateSols() {
    map<int, int> cnt;
    for (int i = 0; i <= 9; i++) cnt[i] = 0;
    for (int j = 1; j < 10000; j++) {
        int i = j;
        while (i > 0)
            cnt[i % 10]++, i /= 10;
        stringstream ss;
        for (auto it1 = cnt.begin(); it1 != --cnt.end(); ++it1)
            ss << it1->second << " ";
        ss << (--cnt.end())->second;
        sols[j] = ss.str();
    }
}

int main() {
    generateSols();
    int T;
    cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << sols[N] << endl;
    }

    return 0;
}